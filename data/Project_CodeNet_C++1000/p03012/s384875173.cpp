#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i < (n); i++)
using namespace std;
typedef long long ll;

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  int ans=100010005;
  rep(i,n){
    int sum_1=0;
    int sum_2=0;
    rep(j,i){
      sum_1 += a[j];
    }
    for (int k=i; k <n; k++){
      sum_2 += a[k];
    }
    ans = min(ans, abs(sum_1 - sum_2));
    //cout << sum_1 << sum_2 << endl;
  }
  cout << ans << endl;
}
