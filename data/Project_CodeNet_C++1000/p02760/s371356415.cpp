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
	map<ll,ll>ch2;
	ll n;
	cin>>n;
	for(ll i=0;i<n;i++){
		ll now;
		cin>>now;
		ch2[now]++;
	}
	for(ll i=0;i<3;i++){
		vector<ll>cnt;
		for(ll j=0;j<3;j++){
			ll now=ch[i][j];
			cnt.push_back(now);
		}
		for(ll j=0;j<3;j++){
			if(ch2[cnt[j]]==0){
				break;
			}
			if(j==2){
				cout << "Yes";
				return 0;
			}
		}
	}
	for(ll i=0;i<3;i++){
		vector<ll>cnt;
		for(ll j=0;j<3;j++){
			ll now=ch[j][i];
			cnt.push_back(now);
		}
		for(ll j=0;j<3;j++){
			if(ch2[cnt[j]]==0){
				break;
			}
			if(j==2){
				cout << "Yes";
				return 0;
			}
		}
	}
	if(ch2[ch[0][0]]==1&&ch2[ch[1][1]]==1&&ch2[ch[2][2]]==1){
		cout << "Yes";
		return 0;
	}
	if(ch2[ch[2][0]]==1&&ch2[ch[1][1]]==1&&ch2[ch[2][0]]==1){
		cout << "Yes";
		return 0;
	}	
	cout << "No";
	// your code goes here
	return 0;
}