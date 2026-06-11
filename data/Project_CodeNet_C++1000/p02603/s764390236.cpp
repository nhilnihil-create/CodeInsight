#include <bits/stdc++.h>  
using namespace std;
#define rep(i,n) for(ll i=0; i<(ll)(n); i++)
using ll = long long int;
 
int main() {
  ll n;
  cin>> n;
  vector<ll> v(n);
  rep(i,n){cin >> v[i];}
  ll stock = 0;
  ll money = 1000;
  rep(i, n - 1){
 
    if(v[i] < v[i + 1]){
      if(stock == 0){
        stock = money / v[i];
        money = money % v[i];
      }
    }
    
    if(v[i] >= v[i + 1]){
      money += stock * v[i];
      stock = 0;
    }
    //cout << money << " " << stock << endl;
  }
  if(stock > 0){money = money + stock * v[n - 1];}
  cout<< money <<endl;
}