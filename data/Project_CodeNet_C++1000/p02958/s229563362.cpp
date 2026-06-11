#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=1e18;

int main(){

  ll n;
  cin >> n;
  ll a=0;
  for(int i=1;i<n+1;i++){
    ll b;
    cin >> b;
    if(b!=i)a++;
  }
  if(a<=2)cout << "YES" << endl;
  else cout << "NO" << endl;
}