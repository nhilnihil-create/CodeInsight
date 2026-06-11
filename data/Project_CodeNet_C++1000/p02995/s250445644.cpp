#include <bits/stdc++.h>

using namespace std;
using ll = long long;

//container util
#define SORT(c) sort((c).begin(),(c).end())
#define all(a) (a).begin(), (a).end()

//repetition
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

//print
#define pv(val) cerr << #val << '=' << (val) << endl

const int INF = 1e9;


ll gcd(ll a, ll b)
{
	if (a%b == 0) return(b);
	else return(gcd(b, a%b));
}

ll lcm(ll a, ll b)
{
	return a * b / gcd(a, b);
}


ll f(ll x, ll C, ll D){

	ll cnt = x;
	cnt -= x/C + x/D - x/lcm(D, C);
	return cnt;
}

int main(void){

	ll A, B, C, D; cin >> A >> B >> C >> D;

	ll ans = (f(B, C, D) - f(A-1, C, D));
	cout << ans << endl;



	return 0;

}
