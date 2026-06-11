#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;
vector <int> n;

int main(){
	long long n,t,ans=0;
	vector <int> a;
	map <int,int> s;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>t;
		a.push_back(t);
		if(s[t]==0){
			s[t]++;
		}else{
			ans+=s[t];
			s[t]++;
		}
	}
	for(int i=0;i<n;i++){
		cout<<ans-s[a[i]]+1<<endl;
	}
	return 0;
}