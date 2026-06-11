#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#define endl "\n"
#define sz(x) ((ll)(x).size())
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define prt(x) cout << (x)
#define prtl(x) cout << (x) << endl
#define rep(i,a,b) for(ll i=a; i<b; i++)
#define rrep(i,a,b) for(ll i=a; i>b; i--)
#define mp(a, b) make_pair(a, b)
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
#define debug(v) cout << #v<< ": " << v <<endl;
using namespace std;
using vi = vector<int>;
using vll = vector<long long int>;
using vb = vector<bool>;
using vvb = vector<vector<bool>>;
using vc = vector<char>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<long long int>>;
using vvc = vector<vector<char>>;
using ll = long long int;
using P = pair<long long int, long long int>;
using Map = map<long long int, long long int>;
ll INF = 1LL<<60;

void dfs(ll p, ll a, ll b, const vvll &e, vector<vector<P>> &n, vb &ad, queue<ll> &q, vvb &md){
    md[p][a%3] = true;
    if(a == 3){
        n[b].emplace_back(mp(p, 1));
        if(!ad[p]){
            q.push(p);
        }
        return;
    }else{
        for(auto x: e[p]){
            if(!md[x][a+1]){
                dfs(x, a+1, b, e, n, ad, q, md);
            }
        }
    }
}

void mfs(ll a, const vector<vector<P>> &g, vb &ald){
    ald[a] = true;
    for(auto x: g[a]){
        ll p = x.first;
        if(!ald[p]){
            mfs(p, g, ald);
        }
    }
}

int main(){
    ll N, M; cin >> N >> M;
    vvll e(N+1, vll(0));
    rep(i, 0, M){
        ll a, b; cin >> a >> b;
        e[a].emplace_back(b);
    }
    ll s, t; cin >> s >> t;
    vector<vector<P>> n(N+1, vector<P>(0));
    vb ad(N+1,false);
    vvb md(N+1, vb(3, false));
    queue<ll> q;
    q.push(s);
    while(!q.empty()){
        ll a = q.front();
        q.pop();
        if(!ad[a]){
            ad[a] = true;
            dfs(a, 0, a, e, n, ad, q, md);
        }
    }
    rep(i, 1, N+1){
        vector<P> x = n[i];
        //prt(i); prt(": ");
        for(auto y: x){
            //prt(y.first); prt(" ");
        }
        //prt(endl);
    }
    vb ald(N+1);
    mfs(s, n, ald);
    ll size = 0;
    vll lis(0);
    rep(i, 1, N+1){
        if(ald[i]){
            lis.emplace_back(i);
            size++;
        }
    }
    if(!ald[t]){
        prt(-1);
        return 0;
    }
    vll ch(N+1, 0);
    rep(i, 0, sz(lis)){
        ch[lis[i]] = i;
    }
    vector<vector<P>> nn(size, vector<P>(0));
    rep(i, 1, N+1){
        vector<P> x = n[i];
        for(auto y: x){
            nn[ch[i]].emplace_back(mp(ch[y.first], 1));
        }
    }
    //prtl(size);
    //ダイクストラ法
        //vvl GにP(to,cost)って感じで隣接リストにしておく
        //計算量|E|log|V|
        //頂点数N
    priority_queue<P, vector<P>, greater<P>> pq;
    vector<ll> d(size,INF);
    d[ch[s]]=0;
    pq.emplace(P(0, ch[s]));
    while(!pq.empty()){
        P x=pq.top();
        pq.pop();
        ll &y=x.first;
        ll &z=x.second;
        if(y>d[z])continue;
        for(auto p: nn[z]){
            if(d[p.first]>d[z]+p.second){
                d[p.first]=d[z]+p.second;
                pq.emplace(P(d[p.first], p.first));
            }
        }
    }
    prt(d[ch[t]]);
}


