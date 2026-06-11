#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair< ll, ll > Pi;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep2(i,n) for(int i=1;i<=(n);i++)
#define rep3(i,i0,n) for(int i=i0;i<(n);i++)
#define pb push_back
#define mod 1000000007
#define INF 200000000000
#define mp make_pair
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
ll gcd(ll a, ll b) {return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) {return a/gcd(a,b)*b;}
#define all(x) x.begin(), x.end()

bool compare(pair<int, int> a, pair<int, int> b) {
    if(a.first != b.first){
        return a.first < b.first;
        
    }else{
        return a.second < b.second;
    }
}
// 入力



int main() {
    ll N;
    cin >>N;
    vector<vector<ll>> t(N);
    vector<pair<ll,ll>> ab(N-1);
    vector<ll> ans(N-1);
    map<Pi,ll> m;
    rep(i,N-1){
        ll a,b;
        cin >>a>>b;
        a--;b--;
        t[a].pb(b);
        t[b].pb(a);
        ab[i].first = a;
        ab[i].second = b;
        m[mp(a,b)]=i;
        m[mp(b,a)]=i;
    }
    ll K = 0;
    rep(i,N){
        ll s = t[i].size();
        chmax(K,s);
    }

    vector<ll> dist(N,-1);
    queue<Pi> que;

    dist[0] = 0;
    que.push(mp(0,-1));

    while(!que.empty()){
        Pi p = que.front();
        ll v=p.first;
        ll n=p.second; 
        que.pop();
        ll cnt=0;
        for(ll i : t[v]){
            if(dist[i] !=-1) continue;
            if(cnt==n){
                cnt++;
            }
            ans[m[mp(v,i)]]=cnt;
            dist[i] = dist[v] + 1;
            que.push(mp(i,cnt));
            cnt++;
        }
    }


    cout<<K<<endl;
    rep(i,N-1){
        cout<<ans[i]+1<<endl;
    }



    return 0;
    

}