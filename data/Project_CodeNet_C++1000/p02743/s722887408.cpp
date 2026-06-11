#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (ll i = 0; i < (int)(n); i++)
int main(){
  ll a,b,c;
  cin >> a >> b >>c;
  ll p=(c-a-b),q=4*a*b;
  p=p*p;
  if(c-a-b>=0 && q<p){
    cout << "Yes";
  }else{
    cout << "No";
  }
}