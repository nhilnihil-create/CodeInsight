#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
 
int main(){
  ll n , a , b;
  cin >> n >> a >> b;
  ll c = n/(a+b);
  ll d = n%(a+b);
  ll sum;
  if (d >= a){
   sum = c*a + a;
  }
  else{
   sum = c*a + d;
  }
  cout << sum << endl;
  return 0;
}