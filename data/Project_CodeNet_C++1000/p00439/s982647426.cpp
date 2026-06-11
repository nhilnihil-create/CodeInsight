#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n,k;

	while(true){
		int max=0,s=0;
		vector<int> a;

		cin>>n>>k;
		if(n==0&&k==0) break;

		for(int i=0;i<n;i++){
			int t;
			cin>>t;
			a.push_back(t);
		}
		
		for(int i=0;i<k;i++){
			s+=a[i];
		}

		max=s;

		for(int i=1;i<=n-k;i++){
			int t=i+k-1;
			s=s-a[i-1]+a[t];
			if(max<s) max=s;
		}

		cout<<max<<endl;
	}
	return 0;
}