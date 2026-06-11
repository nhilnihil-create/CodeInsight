#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	map<ll,ll>ch;
	for(ll i=0;i<3;i++){
		ll now;
		cin>>now;
		ch[now]++;
	}
	for(auto itr=ch.begin();itr!=ch.end();itr++){
		ll val=itr->first;
		ll num=itr->second;
		if(num==2){
			cout <<"Yes";
			return 0;
		}
	}
	cout << "No";
	// your code goes here
	return 0;
}