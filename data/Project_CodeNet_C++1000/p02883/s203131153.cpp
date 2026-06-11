#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <string>
#include <iomanip>
using namespace std;
int main(){
	long long n,k;
	vector<long long> a,f;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		int A;
		cin>>A;
		a.push_back(A);
	}
	for(int i=0;i<n;i++){
		int F;
		cin>>F;
		f.push_back(F);
	}
	sort(a.begin(),a.end());
	sort(f.begin(),f.end());
	long long l=0,r=2e18;
	while(l!=r){
		long long m=(l+r)/2;
		long long cnt=0;
		vector<long long> am;
		for(int i=0;i<n;i++){
			am.push_back(m/f[i]);
		}
		sort(am.begin(),am.end());
		for(int i=0;i<n;i++){
			if(a[i]>am[i]){
				cnt+=(a[i]-am[i]);
			}
		}
		if(cnt<=k){
			r=m;
		}else{
			l=m+1;
		}
	}
	cout<<r<<endl;
	return 0;
}
