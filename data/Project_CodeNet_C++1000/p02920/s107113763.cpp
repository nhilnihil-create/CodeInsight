#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,big=0;
multiset<int> s;
int main(){
	cin>>n;
	for(int i=1;i<=(1<<n);i++){
		ll e;
		cin>>e;
		s.insert(e);
		big=max(big,e);
	}
	vector<int> t;
	t.push_back(big);
	s.erase(s.find(big));
	for(int i=0;i<n;i++){
		vector<int> ut;
		for(ll e:t){
			auto itr=s.lower_bound(e);
			if(itr==s.begin()){
				cout<<"No"<<endl;
				return 0;
			}
			itr--;
			ut.push_back(*itr);
			s.erase(itr);
		} 
		for(ll e:ut){
			t.push_back(e);
		}
	}
	cout<<"Yes"<<endl;
	return 0;
}