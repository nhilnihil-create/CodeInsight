#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
typedef long long ll;
typedef pair<int,int>pii;
const ll mod = 1e9+7;
const int N = 1e5;
ll two[N+100],three[N+100];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	two[0] = 1,three[0] = 1;
	for(int i=1;i<=N;i++){
		two[i] = (two[i-1]*2)%mod;
		three[i] = (three[i-1]*3)%mod;
	}
	string s;
	cin >> s;
	ll ans = 0;
	int sz = s.size(),cnt = 0;
	for(int i=0;i<sz;i++){
		if(s[i]=='1'){
			ans = (ans+((two[cnt]*three[sz-1-i])%mod))%mod;
			cnt++;
		}
	}
	ans = (ans+two[cnt])%mod;
	cout << ans << "\n";
}
