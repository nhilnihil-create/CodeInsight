#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
const int inf = 1001001001;


vector<int> e[200000];
ll num[200000];

void dfs(int i, int p){
  for(int j : e[i]) {
    if(j != p){
      num[j] += num[i];
      dfs(j,i);
    }
  }
}

int main(){
  int n,q;
  cin >> n >> q;

  rep(i,n-1) {
    int a,b;
    cin >> a >> b;
    e[a-1].push_back(b-1);
    e[b-1].push_back(a-1);
  }
  rep(i,q){
    int p,x;
    cin >> p >> x;
    num[p-1] += x;
  }
  dfs(0,-1);
  rep(i,n) cout << num[i] << " ";
  
}
