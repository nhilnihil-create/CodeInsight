#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1000000007;

int main(){
  ll n;
  cin >> n;
  vector<pair<ll,ll>>a(n);
  for(int i=0; i<n; i++ ){
    ll x,y;
    cin >> x >> y;
    a[i].first=x+y;
    a[i].second=x-y;
  }
  sort(a.begin(),a.end());
  
  ll count=0;
  for(int i=0; i<n; i++){
    ll base=a[i].second;
    bool next=false;
    ll j=i;
    while(!next){
      j++;
      if(a[j].second>=a[i].first){
        i=j-1;
        next=true;
        count++;
      }
    }
  }
  
  
  cout << count << endl;
  
}
  
  
  
