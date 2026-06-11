#include <bits/stdc++.h>
#define r(i,n) for(int i = 0; i<n; i++)
typedef long long ll;
using namespace std;
const ll mod=1000000007;

int main() {
  ll n,ans=1;
  cin >> n;
  int s[n]={};
  
  r(i,n){
    int a;
    cin >> a;
    if(a) ans*=s[a-1]-s[a];
    else ans*=3-s[0];
    ans%=mod;
    s[a]++;
  }
  
  cout<<ans<<endl;
}