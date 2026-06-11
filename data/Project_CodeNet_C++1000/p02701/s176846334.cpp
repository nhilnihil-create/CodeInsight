#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
typedef long long ll;
using namespace std;
map<string,bool> k;
int main()
{
	ios_base::sync_with_stdio();
	cin.tie(0);cout.tie(0);
	ll n;
	string s;
	cin >> n;
	ll ans=0;
	while(n--){
		cin >> s;
		if(!k[s]){
			ans++;
			k[s]=true;
		}
	}
	cout << ans << endl;
}