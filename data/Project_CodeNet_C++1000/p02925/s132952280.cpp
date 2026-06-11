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
    ll n; cin >> n;
    map<ll, queue<ll>> a;
    repf(i, n) rep(j, n-1){
        ll num; cin >> num;
        a[i].push(num);
    }

    ll cnt = 0;
    queue<ll> pos;
    while(1){
        ll chk_f = 0;
        vector<bool> chk(n+1, false);
        if(cnt == 0){
            // 初回
            for(ll i=1; i<=n; i++){
                ll cur = i, f = 1001;
                bool hit = false;
                // すでにチェック済みの場合
                if(chk[cur] == true) continue;
                // キューが空の場合
                if(!a[cur].size()){
                    chk[cur] = true;
                    continue;
                }

                while(1){
                    // 先頭要素を読み出す
                    f = a[cur].front();

                    // チェック
                    chk[cur] = true;

                    // 読みだした要素がチェック済みの場合
                    if(chk[f] == true) break;

                    // 読みだした要素のキューが空の場合
                    if(!a[f].size()) break;

                    if(a[f].front() == cur){
                        hit = true;
                        chk[f] = true;
                        break;
                    }
                    else cur = f;
                }
                if(hit){
                    pos.push(cur);
                    pos.push(f);
                    a[f].pop();
                    a[cur].pop();
                    chk_f++;
                }
            }
        }
        else{
            // 2回目以降は1回目の変更箇所だけ見ていけば良い
            ll pos_size = pos.size();
            while(pos_size > 0){
                pos_size--;
                auto f = pos.front();
                pos.pop();
                if(chk[f] == true) continue;
                if(!a[f].size()) continue;

                ll p = a[f].front();
                if(chk[p] == true) continue;
                if(!a[p].size()) continue;

                if(a[p].front() == f){
                    chk_f++;
                    chk[f] = true;
                    chk[p] = true;
                    pos.push(p);
                    pos.push(f);
                    a[f].pop();
                    a[p].pop();
                }
            }
        }
        if(chk_f == 0) break;
        cnt++;
    }

    for(auto &p: a) if(p.second.size() != 0) cnt = -1;
    cout << cnt << endl;
}