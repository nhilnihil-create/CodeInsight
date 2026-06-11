#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n) ;i++)

using namespace std;
using p=pair<int,int>;
typedef long long ll;

int main() {
  ll h,n;
  cin >> h >> n;
  ll a[n];
  rep(i,n){
    cin >> a[i];
  }
  rep(i,n){
    h-=a[i];
  }
  if(h<=0){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
  return 0;

}

