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
    ll n, m; string s;
    cin >> n >> m >> s;

    // 逆順から貪欲に最短手数を求める
    vi backGreedyPath = {n};
    ll now = n;
    while(now > 0){
        // 次の手でゴール地点にたどり着ける場合
        if(now - m <= 0){
            backGreedyPath.push_back(0);
            now = 0; break;
        }
        bool moveChk = false;
        // 移動距離が大きい順から見ていく
        for(ll i = m; i>0; i--){
            if(s[now-i] == '0'){
                now -= i;
                backGreedyPath.push_back(now);
                moveChk = true;
                break;
            }
        }
        // 移動不可な場所がある場合
        if(!moveChk){
            cout << -1 << endl;
            return 0;
        }
    }
    for(ll i=backGreedyPath.size()-1; i>0; i--){
        cout << backGreedyPath[i-1]-backGreedyPath[i] << (i == 1 ? endl : " ");
    }
    return 0;
}