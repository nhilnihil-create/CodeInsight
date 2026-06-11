#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll, ll> Pll;
#define debug(var)  do{std::cout << #var << " : ";view(var);}while(0)
template<typename T> void view(T e){std::cout << e << std::endl;}
template<typename T> void view(const std::vector<T>& v){for(const auto& e : v){ std::cout << e << " "; } std::cout << std::endl;}
template<typename T> void view(const std::vector<std::vector<T> >& vv){ for(const auto& v : vv){ view(v); } }
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const int MOD = 1000000007;
const int INF = 1e9;

const int mod = 1000000007;
const int inf = 1e9;
#define PI acos(-1);
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int ddx[8] = {1,1,1,-1,-1,-1,0,0};
int ddy[8] = {0,1,-1,0,1,-1,1,-1};

set<ll> all_divisor(ll n){
	set<ll> res;
	for(ll i = 1; i*i<= n; i++){
		if(n%i==0){res.insert(i);res.insert(n/i);}
	}
	return res;
}

int main(){
    ll n;
    cin >> n;
    int ans = 0;
    auto s = all_divisor(n-1);
    ans += s.size() - 1;
    auto ss = all_divisor(n);
    for(auto p : ss) {
        if(p == 1) continue;
        ll nn = n;
        while(nn%p == 0) {
            nn /= p;
        }
        if((nn-1)%p==0) ans++;
    }
    cout << ans << endl;
}