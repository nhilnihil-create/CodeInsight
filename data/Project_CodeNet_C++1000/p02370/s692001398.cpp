#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <stack>
#include <numeric>
#include <algorithm>
#include <tuple>
#include <stdio.h>
#include <bitset>
#include <limits.h>
#include <complex>
#include <deque>
#include <iomanip>
#include <list>
#include <cstring>
using namespace std;
#define pi pair<int,int>
#define pl pair<long long,long long>
#define chmax(a,b) (a<b ? a=b:0)
#define chmin(a,b) (a>b ? a=b:0)
#define en cout << endl //セミコロンつけろ
//#define MM 1000000000
//#define MOD MM+7
typedef long long ll;
const int MM = 1e9;
const int MOD = MM+7;
const long double PI = acos(-1);
const long long INF = 1e15;
int dx[8] = {-1,0,1,0,-1,-1,1,1};
int dy[8] = {0,-1,0,1,-1,1,1,-1};
// 'A' = 65, 'Z' = 90, 'a' = 97, 'z' = 122

template<typename T> //最大公約数
T GCD(T u,T v){
    return v ? GCD(v,u%v) : u;
}
template<typename T> //最小公倍数
T LCM(T x,T y){
    T gc = GCD(x,y);
    return x*y/gc;
}

struct edge
{
    int to, cost;
};

vector<vector<int> > g;
vector<int> isVisited, out;
void Topological(int pos){
    isVisited[pos] = true;
    for (int i = 0; i < g[pos].size(); i++){
        if (!isVisited[g[pos][i]]){
            Topological(g[pos][i]);
        }
    }
    out.push_back(pos);
}

int main(){
    int V, E; cin >> V >> E;
    g.resize(V);
    isVisited.resize(V, 0);
    vector<int> IsVisited(V, 0);
    for (int i = 0; i < E; i++){
        int s, t; cin >> s >> t;
        g[s].push_back(t);
    }
    for (int i = 0; i < V; i++){
        if (isVisited[i]) continue;
        Topological(i);
    }
    reverse(out.begin(), out.end());
    for (int i = 0; i < out.size(); i++){
        cout << out[i] << endl;
    }
}
