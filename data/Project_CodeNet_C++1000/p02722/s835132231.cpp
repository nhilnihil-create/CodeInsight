#include <bits/stdc++.h>
#define ll long long
#define MODV 1000000007
#define INFLL LLONG_MAX // 9223372036854775807
#define EPS 1e-9
#define rep(i, n) for(ll i=0, i##_len=(ll)(n); i<i##_len; i++)
#define repf(i, n) for(ll i=1, i##_len=(ll)(n+1); i<i##_len; i++)
#define all(v) v.begin(), v.end()
#define endl "\n"
#define vi vector<ll>
#define vvi vector<vector<ll>>
#define Yes() cout << "Yes" << endl
#define YES() cout << "YES" << endl
#define No() cout << "No" << endl
#define NO() cout << "NO" << endl
#define Init() std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout<<fixed<<setprecision(15);
template<class T>bool chmax(T &a, const T &b){ if(a<b){ a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b){ if(b<a){ a=b; return 1; } return 0; }
using namespace std;

// 約数列挙：nの約数を昇順に返す。
vector<long long> enumDivisors(long long n){
    vector<long long> ret;
    for(long long i=1; i*i<=n; i++){
        if(n%i == 0){
            ret.push_back(i);
            if(n/i != i) ret.push_back(n/i);
        }
    }
    sort(ret.begin(), ret.end());
    return ret;
}

int main(){
    Init();
    ll n; cin >> n;
    ll ans = 0;

    {
        // kで割れない場合
        auto eDiv = enumDivisors(n-1);
        ans += (eDiv.size()-1);
    }
    {
        // kで割れる場合
        auto eDiv = enumDivisors(n);
        for(ll i=1; i<eDiv.size(); i++){
            ll tmp = n/eDiv[i];
            while(tmp%eDiv[i] == 0) tmp = tmp/eDiv[i];
            if(tmp%eDiv[i] == 1) ans++;
        }
    }
    cout << ans << endl;
}