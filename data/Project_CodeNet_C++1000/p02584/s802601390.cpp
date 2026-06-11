#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <numeric>
#include <set>
#include <unordered_set>
#include <queue>
#include <cmath>
#include <bitset>

using namespace std;
#define ll long long
#define rep(i, n) for(int i = 0;i < n;i++)
#define FOR(i, n, m) for(int i=n; i<m; ++i)

using Graph = vector<vector<int>>;

// 深さ優先探索
vector<bool> seen;
void dfs(const Graph &G, int v) {
    seen[v] = true; // v を訪問済にする

    // v から行ける各頂点 next_v について
    for (auto next_v : G[v]) { 
        if (seen[next_v]) continue; // next_v が探索済だったらスルー
        dfs(G, next_v); // 再帰的に探索
    }
}

bool IsPrime(int num)
{
    if (num < 2) return false;
    else if (num == 2) return true;
    else if (num % 2 == 0) return false; // 偶数はあらかじめ除く

    double sqrtNum = sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2)
    {
        if (num % i == 0)
        {
            // 素数ではない
            return false;
        }
    }

    // 素数である
    return true;
}

int main() {
  ll X, K, D;
  cin >> X >> K >> D;
  
  X=abs(X);
  
  if(X/K>=D){
    cout << X-D*K << endl;
  }else{
    ll tmp = X/D;
    ll pl = X - tmp*D;
    ll ms = X - (tmp+1)*D;

    if((tmp%2)==(K%2)){
      cout << pl << endl;
    }else{
      cout << -ms << endl;
    }
  }
}