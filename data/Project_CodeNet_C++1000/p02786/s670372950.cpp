#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef tuple<int,int,int> tii;
#define rep(i,s,n) for(int i=(int)(s);i<(int)(n);i++)


int main(){
 ll H;
 cin >> H;
 ll x = 1;
 ll ans = 0;
 while(x<=H){
   ans += x;
   x *= 2;
 }
  cout << ans << endl;
}
