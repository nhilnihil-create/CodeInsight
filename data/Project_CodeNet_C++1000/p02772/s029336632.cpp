#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;

int main(){
  int n;
  string ans="APPROVED";
  cin >> n;
  vector<int> a(n);
  rep(i, n){
    cin >> a[i];
    if(a[i]%2==0){
      if(a[i]%3==0||a[i]%5==0){
        ans="APPROVED";
      }
      else{
        ans="DENIED";
        break;
      }
    }
  }

  cout << ans << endl;

  return 0;
}