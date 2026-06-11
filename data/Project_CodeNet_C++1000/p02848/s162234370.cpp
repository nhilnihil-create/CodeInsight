#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=1e18;

int main(){

  ll n;
  string s;
  cin >> n >>s;


  for(ll i=0;i<s.size();i++){
    ll b=(s[i]-0+n-65)%26+65;
    char c=b;
    s[i]=c;
  }

  for(ll i=0;i<s.size();i++)cout << s[i];

}