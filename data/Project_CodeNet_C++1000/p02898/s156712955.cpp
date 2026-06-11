#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=1e18;

int main(){

  ll n,k;
  cin >> n >> k;
  ll s=0;
  for(int i=0;i<n;i++){
    ll h;
    cin >> h;
    if(h>=k)s++;
  }
  cout << s << endl;


}