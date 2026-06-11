#include <bits/stdc++.h>
#define For(i, a, b) for(int (i)=(a); (i)<(b); ++(i))
#define rFor(i, a, b) for(int (i)=(a)-1; (i)>=(b); --(i))
#define rep(i, n) For((i), 0, (n))
#define rrep(i, n) rFor((i), (n), 0)
#define fi first
#define se second
using namespace std;
typedef long long lint;
typedef unsigned long long ulint;
typedef pair<int, int> pii;
typedef pair<int, lint> pil;
typedef pair<lint, int> pli;
template<class T>bool chmax(T &a, const T &b){if(a<b){a=b; return true;} return false;}
template<class T>bool chmin(T &a, const T &b){if(a>b){a=b; return true;} return false;}

constexpr lint mod = 1e9+7;
constexpr lint INF = mod*mod;
constexpr int MAX = 200010;

int main(){
        int n;
        scanf("%d", &n);
        int a[n];
        rep(i, n) scanf("%d", &a[i]);
        sort(a, a+n);
        vector<pii> ans;
        int m=a[0], M=a[n-1];
        For(i, 1, n-1){
                if(a[i]>0){
                        ans.emplace_back(m, a[i]);
                        m-=a[i];
                }
                else{
                        ans.emplace_back(M, a[i]);
                        M-=a[i];
                }
        }
        ans.emplace_back(M, m);
        printf("%d\n", M-m);
        for(pii p: ans) printf("%d %d\n", p.fi, p.se);
}