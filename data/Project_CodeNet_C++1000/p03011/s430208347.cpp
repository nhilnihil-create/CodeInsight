#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=1e18;

int main(){

  ll p,q,r;
  cin >> p >> q >>r;
  ll a=max(max(p,q),r);
  cout << p+q+r-a << endl;

}