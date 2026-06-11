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


int main(){ 
    string s; cin >> s;
    int n = s.size();
    ll res = 0;
    int up = 0, down = 0, is_up = true;
    rep(i, n){
        if(s[i]=='<'){
            if(!is_up){
                //集計
                res += max(up, down);
                rept(num, 1, up)res += num;
                rept(num, 1, down)res += num;

                up = 0, down = 0;
                is_up = true;
            }
            up++;
        }else{
            if(is_up){is_up = false;}
            down++;
        }
    }
    res += max(up, down);
    rept(num, 1, up)res += num;
    rept(num, 1, down)res += num;

    cout << res << ln;
}

