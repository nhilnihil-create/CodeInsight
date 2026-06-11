#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=1e18;

int main(){

  ll a,b;
  cin >> a >> b;
  if(a>b)swap(a,b);

  for(ll i=0;i<b;i++)cout << a;

}