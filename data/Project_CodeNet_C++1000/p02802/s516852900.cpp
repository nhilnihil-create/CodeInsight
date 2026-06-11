#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=1e18;

int main(){

  ll n,m;
  cin >> n>> m;

  ll a[n+1]={};
  bool b[n+1]={};

  ll c=0;
  ll d=0;

  for(ll i=0;i<m;i++){
    ll p;
    string s;
    cin >> p >> s;
    if(s=="AC"){
      b[p]=true;
    }
    else{
      if(b[p]);
      else{
        a[p]++;
      }
    }
  }

  for(ll i=1;i<=n;i++){
    if(b[i]){
      c++;
      d+=a[i];
    }
  }

  cout << c <<" " << d << endl;

}