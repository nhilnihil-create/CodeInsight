#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll, ll> Pll;
#define rep(i,n) for(int (i) = 0; (i) < (int)(n); (i)++)
#define srep(i,l,n) for(int i = l; i < (int)(n); i++)
#define drep(i,n) for(int i = (int)(n-1); i >= 0; i--)
#define debug(var)  do{std::cout << #var << " : ";view(var);}while(0)
template<typename T> void view(T e){std::cout << e << std::endl;}
template<typename T> void view(const std::vector<T>& v){for(const auto& e : v){ std::cout << e << " "; } std::cout << std::endl;}
template<typename T> void view(const std::vector<std::vector<T> >& vv){ for(const auto& v : vv){ view(v); } }
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
void Yes(){cout << "Yes" << endl;}
void No(){cout << "No" << endl;}
void YES(){cout << "YES" << endl;}
void NO(){cout << "NO" << endl;}
void err() {cout << -1 << endl;}
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back

const int MOD = 1000000007;
const int INF = 1e9;

#define PI acos(-1);
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int ddx[8] = {1,1,1,-1,-1,-1,0,0};
int ddy[8] = {0,1,-1,0,1,-1,1,-1};

map<ll, int> prime_factor(ll n){
	map<ll, int> res;
	for(ll i = 2; i*i<=n; i++){
		while(n%i==0){
			res[i]++;
			n/=i;
		}
	}
	if(n!=1) res[n]++;
	return res;
}

set<ll> all_divisor(ll n){
	set<ll> res;
	for(ll i = 1; i*i<= n; i++){
		if(n%i==0){res.insert(i);res.insert(n/i);}
	}
	return res;
}


int main(){
    ll n, k;
    cin >> n >> k;
    vector<int> a(n);
    ll sum = 0;
    rep(i, n) cin >> a[i], sum += a[i];
    auto s = all_divisor(sum);

    auto ok = [&](ll x) {
        vector<int> b;
        rep(i, n) {
            if(a[i] % x > 0) b.push_back(a[i]%x);
        }
        sort(all(b));
        int N = b.size();
        vector<ll> sumL(N+1, 0), sumR(N+1, 0);
        rep(i, N) sumL[i+1] = sumL[i] + b[i];
        drep(i, N) sumR[i] = sumR[i+1] + (x-b[i]);
        ll ret = INF;
        rep(i, N) chmin(ret, max(sumL[i], sumR[i+1]));
        return ret <= k;
    };
    ll ans = 1;
    for(auto p : s) {
        if(ok(p)) ans = p;
    }
    cout << ans << endl;
}