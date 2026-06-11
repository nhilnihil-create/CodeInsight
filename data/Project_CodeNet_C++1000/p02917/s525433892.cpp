#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
const int inf = 1001001001;


//A 2 2 5
//B 2 5

//decide from back
//0   0   10  10  10  23
//0  153  10  10  23

//A is stricted by i and i-1 

int main(){
  int n;
  cin >> n;
  vector<int> a(n), b(n-1);
  rep(i,n-1) cin >> b[i];

  rep(i,n){
    if(i == 0){
      a[0] = b[0];
      continue;
    }
    if(i == n-1){
      a[i] = b[i-1];
      continue;
    }
    a[i] = min(b[i],b[i-1]);
  }

  int ans = 0;
  rep(i,n) ans += a[i];
  cout << ans << endl;

  
}
