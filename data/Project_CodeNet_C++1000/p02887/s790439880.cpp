#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=1e18;

int main(){

  ll n;
  string s;
  cin >> n >> s;

  char a='1';
  ll c=0;

  for(ll i=0;i<n;i++){
    if(s[i]!=a){
      a=s[i];
      c++;
    }
  }
  cout << c <<endl;


}