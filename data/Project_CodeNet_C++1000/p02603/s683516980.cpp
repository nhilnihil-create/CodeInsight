#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep1(i, n) for(int i = 1; i < n+1; i++)
#define all(A) A.begin(),A.end()
typedef long long ll;

int main(){
  ll n;
  cin >> n;
  ll money = 1000;
  ll s;//start
  cin >> s;
  ll k = 0;//kabu
  rep(i,n){
    if (i < n-1){
      ll a;
      cin >> a;
      if(s <= a){
        k += money/s;
        money %= s;
      }else{
        money += k*s;
        k = 0;
      }
      s = a;
    }
    if (i == n-1){
      money += k*s;
      k = 0;
    }
  }
  cout << money << endl;
}