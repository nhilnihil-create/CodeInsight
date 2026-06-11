#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n) ;i++)

using namespace std;
using p=pair<int,int>;
typedef long long ll;
const double pi=3.14159265;

int main() {
  ll n,m,ans;
  cin >> n >> m;
  ans=0;
  rep(i,m){
    ll a;
    cin >> a;
    ans+=a;
  }
  ll fin;
  if(ans<=n){
    fin =n-ans;
    cout << fin << endl;
  }
  else if(ans >n){
    cout <<-1<< endl;
  }
  return 0;
  
}