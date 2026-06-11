/*
  The Island Was Silent before.
  .....
  And One day again it became Silent.
*/
#include<bits/stdc++.h>
using namespace std;
 
#define endl '\n'
#define ll  long long
#define modd(a,b) ((a+2*b)%b)
#define debug(a) cout << #a << ": " << (a) << "\n"
#define ioso ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define rtt cerr << "Time: " << clock()*1.0 / CLOCKS_PER_SEC << endl;
#define ffe freopen("input.txt","r",stdin), freopen("output.txt","w",stdout);
 
int main() {
  ioso
  #ifndef ONLINE_JUDGE
  ffe
  #endif
  ll n,d; cin >> n >> d;
  int cn=0;
  ll x, y;
  for(int i=0;i<n;i++) {
    cin >> x >> y;
    if((double)sqrt((x*x) + (y*y)) <=d) {
      cn++;
    }
  }
  cout << cn << endl;
}