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
  ll N; cin >> N;
  ll p = 5;
  if (N%2==0){
    ll ans = 0;
    while (2*p<=N){
      ans += N/2/p;
      p *= 5;
    }
    cout << ans << endl;
  }
  else cout << 0 << endl;


  // cout << fixed << setprecision(10);
  
  return 0;
}
