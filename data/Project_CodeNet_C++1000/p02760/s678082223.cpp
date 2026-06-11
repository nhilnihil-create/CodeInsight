#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll ch[3][3];
	for(ll i=0;i<3;i++){
		for(ll j=0;j<3;j++){
			cin>>ch[i][j];
		}
	}
	ll n;
	cin>>n;
	map<ll,ll>q;
	for(ll j=0;j<n;j++){
		ll now;
		cin>>now;
		q[now]++;
	}
	for(ll i=0;i<3;i++){
		bool ans=true;
		for(ll j=0;j<3;j++){
			if(q[ch[i][j]]==0){
				ans=false;
			}
		}
		if(ans){
			cout << "Yes";
			return 0;
		}
	}
	for(ll i=0;i<3;i++){
		bool ans=true;
		for(ll j=0;j<3;j++){
			if(q[ch[j][i]]==0){
				ans=false;
			}
		}
		if(ans){
			cout << "Yes";
			return 0;
		}
	}
	if(q[ch[0][0]]&&q[ch[1][1]]&&q[ch[2][2]]){
		cout << "Yes";
		return 0;
	}
	if(q[ch[2][0]]&&q[ch[1][1]]&&q[ch[0][2]]){
		cout << "Yes";
		return 0;
	}	
	cout << "No";
	// your code goes here
	return 0;
}