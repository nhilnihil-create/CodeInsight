#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll=long long;

int main(){
  ll n,min=0;
  cin >> n;
  vector<ll> a;
  
  for(ll i=1; i<=sqrt(n); i++){
    if(n%i==0) a.push_back(i);
  }
  ll b=a.size();
  
  for(ll i=0; i<b; i++)
    min=a[i]+n/a[i]-2;
  
  cout << min << endl;
}
