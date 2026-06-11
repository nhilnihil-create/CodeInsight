#include<bits/stdc++.h>
//cervello|Phoenix
using namespace std;
#define ll long long int
#define eb emplace_back
#define mk make_pair
#define all(x) x.begin(),x.end()
#define mod 1000000007

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ll n; cin>>n;
  ll ans = 0;
  for(int i=1; i<=n; i++){
    ans += (n-1)/i;
  }
  cout<<ans<<"\n";
  return 0;
}