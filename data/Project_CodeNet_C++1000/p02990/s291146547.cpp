#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <cmath>
#include <limits>
#define ALL(x) (x).begin(),(x).end()
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define int_INF 2147483647
#define pint_INF 2000000000
#define ll_INF 	9223372036854775807
#define MOD 1000000007
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvll vector<vector<long long>>
#define vvc vector<vector<char>>
#define vll vector<long long>
#define pii pair<int,int>
#define vpii vector<pair<int,int>>
#define sysp system("PAUSE")
#define pno cout << "no" << endl
#define pyes cout << "yes" << endl
#define pYes cout << "Yes" << endl
#define pNo cout << "No" << endl
#define pNO cout << "NO" << endl
#define pYES cout << "YES" << endl
#define endl "\n"
#define pi 3.14159265358979
using namespace std;
using ll = long long;

class MyCombination{
private:
	vector<long long> fac, ifac;
public:
	ll mpow(ll x, ll n) { //x^n(mod M) ←普通にpow(x,n)では溢れてしまうため，随時mod計算
		ll ans = 1;
		while (n != 0) {
			if (n & 1) ans = ans * x % MOD;
			x = x * x % MOD;
			n = n >> 1;
		}
		return ans;
	}

	ll comb(ll a, ll b) { //aCbをmod計算
		if (a == 0 && b == 0)return 1;
		if (a < b || a < 0)return 0;

		ll tmp = ifac[a - b] * ifac[b] % MOD;

		return tmp * fac[a] % MOD;
	}

	MyCombination(long long SIZE = 200001) {
		fac.resize(SIZE);
		ifac.resize(SIZE);
		fac[0] = 1;
		ifac[0] = 1;
		for (ll i = 0; i < SIZE - 1; i++) {
			fac[i + 1] = fac[i] * (i + 1) % MOD; // n!(mod M)
			ifac[i + 1] = ifac[i] * mpow(i + 1, MOD - 2) % MOD; // k!^{M-2} (mod M) ←累乗にmpowを採用
		}
	}
};

int main(){
    ll N,K; cin >> N >> K;
    MyCombination myc;
    for(int i = 1; i <= K; i++){
        ll ans = myc.comb(K-1,i-1);
        ll G = N-K-i+1;
        if(G < 0){
            ans *= 0;
        }else{
            ans *= myc.comb(G+i,i);
        }
        cout << ans%MOD << endl;
    }
    sysp;
}