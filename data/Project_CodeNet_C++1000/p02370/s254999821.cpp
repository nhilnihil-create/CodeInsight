#include <iostream>
#include <stdio.h>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <set>
#include <math.h>
#include <utility>
#include <stack>
#include <string.h>
#include <complex>
using namespace std;

const long long MOD = 1000000007;
const int INF = 1<<29;
const double EPS = 1e-8;
typedef vector<int> vec;
typedef pair<int,int> P;
typedef long long ll;

vector<vec> E;
bool used[10000];
vec vs;

void dfs(int v){
    used[v] = true;
    for(int i=0;i<E[v].size();i++){
        if(!used[E[v][i]]) dfs(E[v][i]);
    }
    vs.push_back(v);
}

int main(){
    int n, m;
    cin >> n >> m;

    E.assign(n, vec());
    for(int i=0;i<m;i++){
        int s, t;
        cin >> s >> t;
        E[s].push_back(t);
    }

    fill(used, used+n, false);
    vs.clear();
    for(int i=0;i<n;i++){
        if(!used[i]) dfs(i);
    }

    for(int i=0;i<n;i++){
        cout << vs[n-1-i] << endl;
    }

    return 0;
}