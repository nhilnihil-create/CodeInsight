#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=1e18;

int main(){

  ll n;
  string s;
  cin >> n>> s;

  ll c=0;

  for(ll i=0;i<n-2;i++){
    if(s[i]=='A' && s[i+1]=='B' && s[i+2]=='C')c++;
  }

  cout << c << endl;

}