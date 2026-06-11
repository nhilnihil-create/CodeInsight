#include <bits/stdc++.h>
#define ll long long int
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define endl '\n'
#define pb push_back
#define mp make_pair
#define all(a) a.begin(),a.end() 
#define max_pqueue priority_queue< long long >
#define min_pqueue priority_queue< long long , vector<long long> , greater< long long >>
#define vi vector<int>
#define vii vector<pair<int, int>>
#define vl vector<long long>
#define vll vector<pair<long long, long long>>
#define FF first
#define SS second
#define PI (double)3.1415926535

//~ setbase - cout << setbase (16); cout << 100 << endl; Prints 64
//~ setfill -   cout << setfill ('x') << setw (5); cout << 77 << endl; prints xxx77
//~ setprecision - cout << setprecision (14) << f << endl; Prints x.xxxx
//~ cout.precision(x)  cout<<fixed<<val;  // prints x digits after decimal in val

#ifndef LOCAL_MACHINE
#define cerr if (false) cerr
#endif

using namespace std;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
template<typename T>
void _printA(T *t, long long sz) { cout<<" { "; for (long long i=0; i<sz; i++) cout<<"["<<i<<"] = "<< t[i]<<endl; cout<<" } \n";}
#ifdef LOCAL_MACHINE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#define debugA(x, y) cerr << "[" << #x << "] = "; _printA(x, y)
#else
#define debug(x...)
#define debugA(x, y)
#endif

const ll _MOD =    998244353LL;

ll mod(ll a, ll m=_MOD) {
	return (a + m) % m;
}

ll gcd(ll a, ll b) { return __gcd(a, b); }

ll gcd(ll a, ll b, ll & x, ll & y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    ll x1, y1;
    ll d = gcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

ll modinv(ll a, ll m=_MOD) {
	ll x, y;
	gcd(a, m, x, y);
	x = (x % m + m) % m;
    return x;
}

ll powm(ll a, ll b, ll m=_MOD) {
	if (b==0) return a % m;
	ll ans = powm(a, b/2, m);
	ans = (ans * ans) % m;
	return (b & 1) ? (ans*(a%m)) % m : ans;
}

/* ------------------------------------------------------------------ */

// 0 indexed BIT
template<class T>
struct BIT {
    vector<T> bit; 
    int n;

    BIT(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    BIT(vector<T> a) : BIT(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    T sum(int r) {
        T ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    T sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, T delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};


void solve() {
	ll N, K;
	cin>>N>>K;
	vector<ll> A(N);
	ll sum = 0;
	vector<ll> divs;
	for (auto &a : A) {
		cin>>a;
		sum += a;
	}
	ll g = sqrt(sum);
	for (int i=1; i<=g; i++) {
		if (sum % i == 0) {
			divs.pb(i);
			if ((sum / i) != i)
				divs.pb(sum/i);
		}
	}
	vector<ll> R(N);
	ll max_gcd = -1;
	for (auto d : divs) {
		for (int i=0; i<N; i++)
			R[i] = A[i] % d;
		sort(R.begin(), R.end());
		ll sum1 = accumulate(R.begin(), R.end(), 0LL);
		
		if (sum1 == 0) {
			max_gcd = max(max_gcd, d);
			continue;
		}
		
		ll sum2 = 0;
		for (int i=N-1; i>=0; i--) {
			sum1 -= R[i];
			sum2 += (d - R[i]);
			if (sum1 == sum2)
				break;
		}
		//~ debug(d, sum2);
		if (sum2 <= K)
			max_gcd = max(max_gcd, d);
	}
	
	cout<<max_gcd<<endl;
}

int main() {
#ifdef LOCAL_MACHINE
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-result"
freopen("in", "r", stdin);
#pragma GCC diagnostic pop
#endif

	fast_io;
	ll T;
	T = 1;
	//~ cin>>T;
	for (ll t=0; t<T; t++) {
		solve();
	}
}	









