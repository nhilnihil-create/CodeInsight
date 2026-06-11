#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  ll x;
  cin >> x;

  ll i = 100;
  int y=0;
  while(1){
    y++;
    i = i + i/100;
    if(i>=x) break;
  }
  cout << y << endl; 
}
