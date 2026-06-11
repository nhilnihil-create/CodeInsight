#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <math.h>
#include <complex>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <bitset>
#include <functional>
#include <assert.h>
using ll=long long;
#define int ll
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(b)-1;i>=int(a);i--)
#define per(i,b) gnr(i,0,b)
#define eb emplace_back
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
#define fi first
#define se second
const int INF = 1e15;
using namespace std;

template<class T> using vc=vector<T>;
template<class T> using vvc=vc<vc<T>>;

using pi=pair<int,int>;
using vi=vc<int>;

template<class T>
inline bool chmax(T &a,T b){if(a<b){a=b;return true;}return false;}
template<class T>
inline bool chmin(T &a,T b){if(a>b){a=b;return true;}return false;}

const int MOD = 1e9+7;

int dfs(vc<vi> &G,int now,int from,int K){
    int ans=1;
    int pos;

    if(G[now].size()>K) return 0;

    if(from==-1) {
        pos=K-1;
        rep(i,G[now].size()){
            ans*=pos;
            ans%=MOD;
            pos--;
        }
    }
    else {
        pos=K-2;
        rep(i,G[now].size()-1){
            ans*=pos;
            ans%=MOD;
            pos--;
        }
    }
    
    for(auto a:G[now]){
        if(a==from) continue;
        else {
            ans*=dfs(G,a,now,K);
            ans%=MOD;
        }
    }
    return ans;
}

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout<<fixed<<setprecision(20);

    int N,K; cin >> N >> K;
    vc<vi> G(N);
    rep(i,N-1){
        int a,b; cin >> a >> b;
        a--; b--;
        G[a].eb(b);
        G[b].eb(a);
    }
    int ans=(K*dfs(G,0,-1,K))%MOD;
    cout << ans << endl;
}