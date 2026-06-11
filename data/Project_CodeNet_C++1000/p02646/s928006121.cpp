#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;

int main(){
  cout << setprecision(10);
  ll A,B,V,W,T;
  cin >> A >> V;
  cin >> B >> W;
  cin >> T;

  string ans;

  if(W >= V){
    ans = "NO";
  } else {
    ll diff = abs(A - B);
    if( (V - W) * T >= diff){
      ans = "YES";
    } else {
      ans = "NO";
    }
  }
  cout << ans << endl;
}
