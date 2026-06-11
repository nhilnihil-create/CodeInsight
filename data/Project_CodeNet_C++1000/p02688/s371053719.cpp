#include <bits/stdc++.h>
#define rep(i,a,n) for (int i = (a); i < (n); i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main(){
  int n,k;
  cin >> n >> k;
  vector<int> have(n,0);
  rep(i,0,k){
    int d;
    cin >> d;
    rep(j,0,d){
      int a;
      cin >> a;
      have[a-1]++;
    }
  }

  int ans = 0;

  rep(i,0,n){
    if(have[i]==0) ans++;
  }

  cout << ans << endl;

  return 0;
}