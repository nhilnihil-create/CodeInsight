#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define INF 1e18
#define PI 3.14159265358979

using namespace std;

ll power(ll n, ll k);
ll inv(ll n);
ll genfact(ll n, ll k);
ll fact(ll n);
ll nck(ll n, ll k);

int main(void){
  int n, m;
  cin >> n >> m;
  vector<vector<int>> edge(3*n, vector<int>(0));

  int u, v;
  for (int i = 0; i < m; i++){
    cin >> u >> v;
    u--; v--;
    edge[3*u].push_back(3*v + 1);
    edge[3*u + 1].push_back(3*v + 2);
    edge[3*u + 2].push_back(3*v);
  }

  int s, t;
  cin >> s >> t;
  s--; t--;


  vector<bool> visited(3*n, false);
  queue<pair<int, int>> q;
  q.push(pair<int, int>(3*s, 0));
  int d, ok = 0;
  while (!q.empty()){
    const pair<int, int> cur = q.front();
    q.pop();
    d = cur.second;
    u = cur.first;

    visited[u] = true;
    for (int i = 0; i < edge[u].size(); i++){
      if (edge[u][i] == 3*t){
        ok = 1;
        d++;
        break;
      }
      if (!visited[edge[u][i]]){
        visited[edge[u][i]] = true;
        q.push(pair<int, int>(edge[u][i], d + 1));
      }
    }
    if (ok)
      break;
  }


  cout << (ok == 1 ? d/3 : - 1) << endl;

  return 0;
}


ll power(ll n, ll k){
  ll res = 1;
  while(k > 0){
    if (k & 1) 
      res = res * n % MOD;
    n = n * n % MOD;
    k >>= 1;
  }
  return res;
}

ll genfact(ll n, ll k){

  ll res = 1;
  while (k >= 0){
    res = (res * (n - k)) % MOD;
    k--;
  }

  return res;
}

ll inv(ll n){
  return power(n, MOD - 2);
}

ll fact(ll n){
  return genfact(n, n - 1);
}

ll nck(ll n, ll k){
  if (k == 0)
    return 1;
  if (n <= 0)
    return 0;

  return ((genfact(n, k) % MOD) * inv(fact(k))) % MOD;
} 
