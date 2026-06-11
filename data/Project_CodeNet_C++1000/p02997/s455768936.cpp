#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define m1(x) memset(x,-1,sizeof(x))
const int INF = 1e9 + 1;
const ll MOD = 998244353;
const double PI = 3.141592653589793;

int main(){
  int n, k;
  cin >> n >> k;
  if(k > (n-1) * (n-2) / 2){
    printf("%d\n", -1);
    return 0;
  }else{
    printf("%d\n", n*(n-1)/2-k);
    for(int i = 2; i <= n; i++){
      printf("%d %d\n", 1, i);
    }
    vector<P> p;
    for(int i = 2; i <= n; i++){
      for(int j = i+1; j <= n; j++){
        p.push_back(P(i, j));
      }
    }
    for(int i = 0; i < (n-1)*(n-2)/2 - k; i++){
      printf("%d %d\n", p[i].first, p[i].second);
    }
  }
}