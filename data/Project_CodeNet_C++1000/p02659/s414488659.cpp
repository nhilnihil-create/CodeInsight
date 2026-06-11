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
  ll a; //long double a;
  
  cin >> a;
  //ll k = (b*100);
  string b; cin >> b;
  //cout << b << endl;
  ll k = ((b[0]-'0')*100 + (b[2]-'0')*10 + b[3]-'0');
  //cout << k << endl;
  ll ans = ((a)*k)/100;
  cout << ans << endl;
}