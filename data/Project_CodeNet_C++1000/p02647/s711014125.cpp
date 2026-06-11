#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main()
{
ll n , k ;
cin >> n >> k ;
vector<ll> a(n);
rep(i, n){
  cin >> a[i];
}

rep(j,min(50LL,k)){
  vector<ll> v(n+1,0);
  rep(i,n){
    v[max(0LL,i-a[i])]++;
    v[min(n,i+a[i]+1)]--;
  }
  a[0]=v[0];
  rep(i,n-1)a[i+1]=a[i]+v[i+1];
}
for(auto an:a)cout << an << " ";
cout << endl;
return 0;
}