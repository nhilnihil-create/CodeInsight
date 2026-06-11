#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=1e18;

int main(){

  ll a,b,c;
  cin >> a >> b >> c;

  if(b+c<=a)cout << 0 << endl;
  else cout << c-(a-b) << endl;

}