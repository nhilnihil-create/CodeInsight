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
typedef pair<lint, int> pli;
typedef complex<double> xy_t;
typedef vector<lint> poly;
template<class T>bool chmax(T &a, const T &b){if(a<b){a=b; return true;} return false;}
template<class T>bool chmin(T &a, const T &b){if(a>b){a=b; return true;} return false;}

const lint mod = 1e9+7;
const lint INF = mod*mod;
const int MAX =200010;

int n;
lint a[MAX], b[MAX];

int main(){
    scanf("%d", &n);
    rep(i, n) scanf("%lld", &a[i]);
    rep(i, n) scanf("%lld", &b[i]);

    priority_queue<pli> que;
    rep(i, n) que.emplace(b[i], i);
    lint ans=0;
    while(!que.empty()){
        pli p=que.top(); que.pop();
        lint val=p.fi;
        int idx=p.se;
        int pre=(idx+n-1)%n, nxt=(idx+1)%n;
        if(val==a[idx] || val-(b[pre]+b[nxt])<a[idx]) continue;
        lint t=(val-a[idx])/(b[pre]+b[nxt]);
        b[idx]-=t*(b[pre]+b[nxt]);
        que.emplace(b[idx], idx);
        ans+=t;
    }
    rep(i, n)if(a[i]!=b[i]){
        printf("-1\n");
        return 0;
    }
    printf("%lld\n", ans);
}