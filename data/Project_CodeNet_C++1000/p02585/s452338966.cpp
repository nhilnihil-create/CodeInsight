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

vector<ll>P, C;
//始点sから1~k回まで回した時の最大得点を返す
ll func(int s, ll k){
    int index = s;
    ll ret = -LINF, score = 0;
    rep(i, k){
        int nx = P[index];
        score += C[nx];
        chmax(ret, score);
        index = nx;
    }
    return ret;
}

int main(){
    ll n, k; cin >> n >> k;
    P.resize(n), C.resize(n);
    rep(i, n){cin >> P[i]; P[i]--;}
    rep(i, n) cin >> C[i];

    ll res = -LINF;
    rep(i, n){
         int index = i, cnt = 0;ll score = 0;
         while(1){
            int nx = P[index];
            score += C[nx];
            index = nx;
            cnt++;
            if(nx == i)break;//一周した
         }
         int r = cnt;//ループ長
         if(k < r){
            chmax(res, func(i, k));
         }else{
            if(score >= 0){
               if(k%r==0){
                  ll tmp = score * (k/r - 1);
                  chmax(res, tmp + func(i, r));
               }else{
                  ll tmp = score * (k/r);
                  chmax(res, tmp + func(i, k%r));
               }
            }else{
                chmax(res, func(i, r-1));
            }
        }
    }
    cout << res << ln;
}
    
