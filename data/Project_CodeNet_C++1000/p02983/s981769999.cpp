#include<bits/stdc++.h>
#include<cctype>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#define all(v) (v).begin(),(v).end()
typedef long long int ll;
#define pi 3.1415926535897932384
#define E9 1000000000
#define eps 1e-4
#define pii pair<int,int>

int main(){
  ll L, R; cin >> L >> R;
  if (R-L<2018 && R/2019==L/2019){

    ll retval = 2019;
    for (ll i=L;i<=R;i++){
      for (ll j=i+1;j<=R;j++){
        retval = min(retval, (i*j)%2019);
      }
    }
    cout << retval << endl;

  }
  else {
    cout << 0 << endl;
  }
  
  // cout << fixed << setprecision(10);
  
  return 0;
}

