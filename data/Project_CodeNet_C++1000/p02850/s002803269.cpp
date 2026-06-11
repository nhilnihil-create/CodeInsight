#include<iostream>
#include<deque>
#include<queue>
#include<vector>
#include<algorithm>
#include<set>
#include<cmath>
#include<tuple>
#include<string>
#include<chrono>
#include<functional>
#include<iterator>
#include<random>
#include<unordered_set>
#include<array>
#include<map>
#include<iomanip>
#include<assert.h>
#include<bitset>
#include<stack>
#include<memory>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define endl "\n"
using namespace std;
using ll = long long;
using P = pair<int,int>;
const double eps = 1e-10;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
const string YES = "";
const string NO = "";

struct edge{
    int id, to;
};

int color[100100];
int _max = -INF;
vector<vector<edge>> g(100100);

void dfs(int v, int p, int pe){
    int cnt = 0;
    for(edge e:g[v]){
        if(e.to == p)continue;
        while(pe!=-1&&cnt == color[pe])cnt++;
        color[e.id] = cnt++;
        dfs(e.to, v, e.id);
    }
    _max = max(_max,cnt);
}

int main() {
    int n;
    cin>>n;
    rep(i,n)color[i] = -1;
    rep(i,n-1){
        int a, b;
        cin >> a >> b; a--; b--;
        g[a].push_back(edge{i, b});
        g[b].push_back(edge{i, a});
    }    
    dfs(0, -1, -1);
    cout << _max << endl;
    rep(i,n-1){
        cout << color[i]+1 << endl;
    }
}
