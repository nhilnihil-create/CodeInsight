#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n) ;i++)

using namespace std;
using p=pair<int,int>;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  ll a[n];
  rep(i,n){
    cin >> a[i];
  }
  sort(a,a+n);
  rep(i,n-1){
    if(a[i]==a[i+1]){
      cout <<"NO" <<endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  

  return 0;

}