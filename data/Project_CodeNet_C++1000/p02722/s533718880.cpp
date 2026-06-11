#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>; 
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = 1001001001LL;
constexpr long long LINF = 1001001001001001001;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

vector<long long> enum_divisors(long long N) {
    vector<long long> res;
    for (long long i = 1; i * i <= N; ++i) {
        if (N % i == 0) {
            res.push_back(i);
            if (N/i != i) res.push_back(N/i);
        }
    }
    sort(res.begin(), res.end());
    return res;
}

int main(){
    ll n; cin >> n;
    /*rept(k, 2, n+1){
        ll m = n;
        rep(i, 1000){
            if(m==1)cout << k << " ";
            if(m%k==0) m /= k;
            else m -= k;
        }
    }
    cout << ln;*/
    set<ll> st{n};
    auto ed = enum_divisors(n-1);
    for(auto p: ed) st.insert(p);

    auto ed2 = enum_divisors(n);
    for(auto a: ed2){
        ll num = n;
        if(a==1)continue;
        while(num%a==0){
            num /= a;
        }
        if(num==1 || num % a == 1)st.insert(a);
    }
    //for(auto tmp: st)cout <<tmp << " ";
    cout << st.size() - 1 << ln;
}
