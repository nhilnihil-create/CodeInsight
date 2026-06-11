#include <bits/stdc++.h>
#define rep(i, n) for(int i= 0; i < (n); i++)
using ll= long long int;
using namespace std;
ll mod= 1e9 + 7;



int main() {
  ll a,b;
  cin >> a>> b;
  if(a<b){swap(a,b);}
  if((a+b)%2==0){cout << (a+b)/2 << endl;}else{cout << "IMPOSSIBLE" << endl;}
}