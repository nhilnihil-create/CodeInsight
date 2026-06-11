#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<string>> vvs;
typedef vector<vector<char>> vvc;
typedef vector<vector<bool>> vvb;
typedef pair<int,int> P;
typedef pair<ll, ll> Pll;
#define vrep(v,n) for(int i=0;i<n;i++){cin >> v.at(i);} 
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repn(i, n) for (int i = 0; i <= (int)(n); i++)
#define srep(i, l, n) for (int i = l; i < (int)(n); i++)
#define srepn(i, l, n) for (int i = l; i <= (int)(n); i++)
#define pb push_back 
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const int mod = 1000000007;
const int inf = 1e9;
#define PI 3.14159265369;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int ddx[8] = {1,1,1,-1,-1,-1,0,0};
int ddy[8] = {0,1,-1,0,1,-1,1,-1};

vector<vector<int>> G;
map<pair<int, int>, int> color;
vector<P> vp;
 


int main(){
    int n;
    cin >> n;
    G.resize(n);
    rep(i,n-1){
        int a, b;
        cin >> a >> b;
        a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
        vp.push_back(P(a, b));
    }
    ll k = 0;
    queue<int> q;
    vector<int> seen(n, 0);
    vector<int> par_col(n);
    seen[0] = 1;
    q.push(0);
    while(!q.empty()){
        int p = q.front();
        q.pop();
        int col = 1;
        chmax(k, (ll)G[p].size());
        for(auto i: G[p]){
            if(seen[i]) continue;
            if(col == par_col[p]) col++;
            par_col[i] = col;
            color[make_pair(p, i)] = col;
            color[make_pair(i, p)] = col;
            col++;
            q.push(i);
        }
      	seen[p] = 1;
    }

    cout << k << endl;

    for(auto v: vp){
        cout << color[v] << endl;
    }

}