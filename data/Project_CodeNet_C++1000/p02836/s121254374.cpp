#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=1e18;

int main(){

  string s;
  cin >> s;
  ll n=s.size();

  ll c=0;
  for(ll i=0;i<n/2;i++)if(s[i]!=s[n-1-i])c++;

  cout << c <<endl;  

}