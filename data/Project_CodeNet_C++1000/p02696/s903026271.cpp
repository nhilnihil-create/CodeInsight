#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tii;
#define rep(i,s,n) for(int i=(int)(s);i<(int)(n);i++)


int main(){
  ll A,B,N;
  cin >> A >> B >> N;
  ll x = min(B-1,N);
  ll ans = (A*x)/B - A*(x/B);
  cout << ans << endl;
}
