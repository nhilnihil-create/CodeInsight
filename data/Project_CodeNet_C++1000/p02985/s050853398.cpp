#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using vl = vector<ll>;
using Map = map<ll,ll>;
using T = tuple<ll,ll,ll>;
using vvl = vector<vector<ll>>;
const ll INF=1LL<<60;
const ll MOD=1000000007;

vector<bool> check(100005,0);
vector<vector<ll>> graph(100005, vector<ll>(0));
vector<ll> parent(100005,0);
vector<vector<ll>> children(100005, vector<ll>(0));
ll ans=1;
bool ng=0;
ll K;

void dfs(ll x){
    check[x]=1;
    for(auto p: graph[x]){
        if(check[p])continue;
        dfs(p);
        parent[p]=x;
        children[x].emplace_back(p);
    }
}

//xを根とする部分木はまだ塗ってない
ll dfs2(ll x){
    //残りは色の候補数
    ll nokori=K-1;
    if(x!=1)nokori--;
    for(auto p: children[x]){
        if(nokori<0)ng=1;
        ans*=nokori;ans%=MOD;
        dfs2(p);
        nokori--;
    ;}
}


int main(){
    ll N;
    cin >> N;
    cin >> K;
    vector<ll> a(N-1,0);
    vector<ll> b(N-1,0);
    for(ll i=0;i<N-1;i++){
        cin>>a[i]>>b[i];
        graph[a[i]].emplace_back(b[i]);
        graph[b[i]].emplace_back(a[i]);
    ;}
    //1を根として考える
    dfs(1);
    //1を塗る
    ans*=K;ans%MOD;

    dfs2(1);


    if(ng){
        cout<<0<<endl;return 0;
    }

    cout<<ans<<endl;


    



    return 0;
}
