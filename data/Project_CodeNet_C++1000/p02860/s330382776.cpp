#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=1e18;

int main(){

  ll n;
  string s;
  cin >> n >> s;

  if(n%2==1)cout << "No" << endl;
  else{
    bool ok=true;
    for(ll i=0;i<n/2;i++){
      if(s[i]!=s[i+n/2])ok=false;
    }
    if(ok)cout << "Yes" << endl;
    else cout << "No" << endl;
  }

}
