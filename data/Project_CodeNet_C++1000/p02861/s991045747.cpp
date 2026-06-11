#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
const int inf = 1001001001;

int main(){
  int n;
  cin >> n;
  vector<pair<double,double>> g(n);

  rep(i,n) cin >> g[i].first >> g[i].second;

  sort(g.begin(),g.end());

  double tot = 0;
  do{
    rep(i,n){
      if(i == n-1) continue;
        double nx = g[i+1].first;
        double ny = g[i+1].second;
        double x = g[i].first;
        double y = g[i].second;
        tot += sqrt((nx-x)*(nx-x)+(ny-y)*(ny-y));
    }
  }while(next_permutation(g.begin(),g.end()));
  
  double div = 1;
  for(int i = 1; i <=n; i++) div *= i;

  printf("%f10\n", tot/div);
}
