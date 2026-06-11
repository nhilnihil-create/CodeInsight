#include <bits/stdc++.h>
using namespace std;
///////////////////////////////////////////
const long long int INF = 1LL<<60;
const long long int Mod = 1000000007;
using ll = long long int; using ci = const int;
using vi = vector<int>;  using Vi = vector<long long int>;
using P = pair<int, int>;  using PLL = pair<ll, ll>;
using matrix = vector<vector<ll>>;
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define rp(i,N) for(ll i = 0; i < (ll)N; i++)
#define repi(i,a,b) for(ll i = ll(a); i < ll(b); ++i)
template<class T>bool chmax(T &former, const T &b) { if (former<b) { former=b; return true; } return false; }
template<class T>bool chmin(T &former, const T &b) { if (b<former) { former=b; return true; } return false; }
template<class T>T sqar(T x){ return x*x; }//sqrt(x)は平方根;
#define Sort(v) std::sort(v.begin(), v.end(), std::greater<decltype(v[0])>()) //降順でVをソート
#define p_queue(v) priority_queue<v, vector<v>, greater<v> >
template<class T> inline void princ(T x){cout<<x<<" ";}; 
template<class T> inline void print(T x){cout<<x<<"\n";};
template<class T> inline void Yes(T condition){ if(condition) cout << "Yes" << endl; else cout << "No" << endl; }
template<class T> inline void YES(T condition){ if(condition) cout << "YES" << endl; else cout << "NO" << endl; }
///////////////////////////////////////////////////////////////////////////////////
struct edge{/*重み付き,有向*/
    int to , cost;/*toは接続先*/
    //edge(ll to_){ to=to_;};/*全てのcost=1 <=> 無向グラフ*/
};
bool operator<(edge e1 ,edge e2){return e1.cost < e2.cost; }
bool operator>(edge e1 ,edge e2){return e1.cost > e2.cost; }
using graph =  vector< vector<edge> >;

Vi indegree;//頂点の入次数を管理.
queue<ll> _q;//入次数0の頂点集合
void _set_indegree(graph _g){//入次数を計算し,配列に持っておく.
    indegree.resize(_g.size());
    rp(i,_g.size()){
        indegree[i] = _g[i].size();
        if(indegree[i]==0){
            _q.push(i);
        }
    }
}

Vi topologicalsort(graph _g){//有向非順回グラフについて,根本からソートされた配列を返す
    Vi sorted;
    graph _g2(_g.size());
    rp(i,_g.size()){
        rp(j,_g[i].size()){
            edge e;
            e.to=i;
            e.cost=1;
            _g2[_g[i][j].to].pb(edge(e));
        }
    }
    _set_indegree(_g2);
    while(!_q.empty()){
        ll now = _q.front();
        _q.pop();
        sorted.pb(now);
        rp(i,_g[now].size()){//入次数が0のものを取り出して,ソート済み配列に突っ込んで,それに隣接する頂点の入次数を更新
            ll id = _g[now][i].to;
            indegree[id]--;
            if(indegree[id]==0){
                _q.push(id);
            }
        }
    }
    return sorted;
}

graph game(1001050,vector<edge>(0));
void solve(){
    ll n;
    cin >> n;
    game.resize(n*(n-1)/2);
    rp(i,n){
        Vi opponent(n-1);
        rp(j,n-1){
            cin >> opponent.at(j);
            if(j==0) continue;
            ll pre=opponent.at(j-1),cur=opponent.at(j);
            ll sm=min(i+1,cur),la=max(i+1,cur);
            edge e;
            e.to=(sm-1)*n-sm*(sm-1)/2+la-sm-1;
            sm=min(i+1,pre); la=max(i+1,pre);
            e.cost=1;
            game[(sm-1)*n-sm*(sm-1)/2+la-sm-1].pb(e);
        }
    }
    Vi order=topologicalsort(game);
    ll game_num=order.size();
    if(game_num!=n*(n-1)/2){
        print(-1);
        return;
    }
    ll ctr=1;
    vi match(n+1,0);
    rp(i,game_num){
        ll A,B;
        ll num=order[i];
        ll ok=1,ng=n;
        ll mid=(ok+ng)/2;
        while(ng-ok>1){
            if((mid-1)*n-mid*(mid-1)/2>num) ng=mid;
            else ok=mid;
            mid=(ok+ng)/2;
        }
        A=ok;
        B=num-((A-1)*n-A*(A-1)/2)+A+1;
        if(match[A]==1||match[B]==1){
            fill(all(match),0);
            match[A]=match[B]=1;
            ctr++;
            continue;
        }
        match[A]=match[B]=1;
    }
    print(ctr);
    return;
}
int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    std::cout<<std::fixed<<std::setprecision(30);
    solve();
    return 0;
}