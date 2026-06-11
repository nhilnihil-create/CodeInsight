#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
#define fi first
#define se second
long long mo = 1000000007;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef pair<ll,Pll> PlP;
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }
template<class A>void PR(A a,ll n){rep(i,n){if(i)cout<<' ';cout<<a[i];}cout << "\n";}
ld PI=3.14159265358979323846;

int main(){
    ll N, M;
    cin >> N >> M;
    vector<vector<ll>> G(N*3);
    //vector<ll> degv(N);
    ll a,b,S,T;
    rep(i,M){
        cin >> a >> b;
        a--;b--;
        G[a].push_back(b+N);
        G[a+N].push_back(b+N*2);
        G[a+N*2].push_back(b);
        
        //degv[b]++;
    }
    cin >> S >> T;
    S--;T--;
    //priority_queue<Pll,vector<Pll>,greater<Pll>> que;
    queue<Pll> que;
    vector<ll> memo(N*3,0), dist(N*3,-1);
    que.push(Pll(0,S));
    while(!que.empty()){
        ll c1 = que.front().fi;
        ll v = que.front().se;
        que.pop();
        /*if(c1 % 3 == 0 && memo[v] != 0) continue;
        if(c1 % 3 == 0){
            memo[v] = 1;
            dist[v] = c1;
        }*/
        if(memo[v] != 0) continue;
        memo[v] = 1;
        dist[v] = c1;
        for(auto& u:G[v]){
            que.push(Pll(c1+1, u));
        }
    }
    if(memo[T]){
        cout << dist[T]/3 << endl;
    }else{
        cout << -1 << endl;
    }
    /*
    queue<ll> que;
    vector<ll> tp, memo(N);
    tp.push_back(S);
    que.push(S);
    while(!que.empty()){
        ll v = que.front();
        que.pop();
        if(memo[v] != 0) continue;
        memo[v] = 1;
        for(auto& u:G[v]){
            degv[u]--;
            que.push(u);
            if(degv[u] == 0){
                tp.push_back(u);
            }
        }
    }
    PR(tp,N);*/
}