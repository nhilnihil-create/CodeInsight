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

int main(){
    Init();
    ll n, k, c; string s;
    cin >> n >> k >> c >> s;
    vi l(k), r(k);

    // 右方向に貪欲で働く日を決める
    ll pos = 0, cnt = 0;
    while(pos < n && cnt < k){
        if(s[pos] == 'o'){
            l[cnt] = pos;
            cnt++;
            pos += c;
        }
        pos++;
    }

    // 左方向に貪欲で働く日を決める
    pos = n-1, cnt = k-1;
    while(pos >= 0 && cnt >= 0){
        if(s[pos] == 'o'){
            r[cnt] = pos;
            cnt--;
            pos -= c;
        }
        pos--;
    }

    // 重なっている日を出力
    rep(i, k) if(l[i] == r[i]) cout << l[i]+1 << endl;
}