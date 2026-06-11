//C
#include <bits/stdc++.h>

using namespace std;

#define DB( x ) cout << #x << " = " << x << endl;
#define LEFT(n) (2 * (n))
#define RIGHT(n) (2 * (n) + 1)

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> node;
//typedef vector <vector <ll>> matrix;

const ll INF = 1e9;
const double EPS = 1e-9;
const ll MOD = (ll)(1e9 + 7);
const ll MAXV = (ll)(2e5 + 10);
const ll MAXE = (ll)(1e6 + 10);



int main(){
	cin.sync_with_stdio( 0 );cin.tie( 0 );

	ll n;

	cin >> n;

	string s;

	cin >> s;

	ll cnt = 0, ans = 1;

	bool ok = true;

	for(int i = 0;i < 2*n;i ++){
		int curr;
		if(s[i] == 'B')
			curr = 1LL;
		else
			curr = 0LL;

		if((cnt + curr) % 2LL)
			cnt ++;
		else{
			ans = (ans * cnt) % MOD;
			cnt --;
		}
		if(cnt < 0){
			ok = false;
			break;
		}
	}

	ll fact = 1LL;
	for(ll i = 1;i <= n;i ++)
		fact = (fact * i) % MOD;

	ans = (ans * fact) % MOD;

	if(cnt != 0)
		ok = false;

	if(ok)
		cout << ans << "\n";
	else
		cout << "0\n";

	return 0;
}
