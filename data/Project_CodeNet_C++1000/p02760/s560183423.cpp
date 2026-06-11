#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll ch[9][9];
	for(ll i=0;i<3;i++){
		for(ll j=0;j<3;j++){
			cin>>ch[i][j];
		}
	}
	ll n;
	cin>>n;
	map<ll,ll>q;
	for(ll i=0;i<n;i++){
		ll now;
		cin>>now;
		q[now]++;
	}
	for(ll i=0;i<3;i++){
		bool ans=true;
		for(ll j=0;j<3;j++){
			ll now=ch[i][j];
			ans=false;
			if(q[now]==1){
				ans=true;
			}
			if(ans==false){
				break;
			}
		}
		if(ans){
			cout<<"Yes";
			return 0;
		}
	}
	for(ll i=0;i<3;i++){
		bool ans=true;
		for(ll j=0;j<3;j++){
			ll now=ch[j][i];
			ans=false;
			if(q[now]==1){
				ans=true;
			}
			if(ans==false){
				break;
			}
		}
		if(ans){
			cout<<"Yes";
			return 0;
		}
	}
	if(q[ch[0][0]]&&q[ch[1][1]]&&ch[ch[2][2]]){
		cout << "Yes";
		return 0;
	}
	if(q[ch[0][2]]&&q[ch[1][1]]&&ch[ch[2][0]]){
		cout << "Yes";
		return 0;
	}
	cout << "No";
	// your code goes here
	return 0;
}