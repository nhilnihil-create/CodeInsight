#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<ll> lunlun = {1, 2, 3, 4, 5, 6, 7, 8, 9};

void make_lunlun(ll a, int n) {
  if (n <= 10) {
    if (a % 10 == 0) {
      lunlun.push_back(a*10);
      make_lunlun(a*10, n+1);
      lunlun.push_back(a*10+1);
      make_lunlun(a*10+1, n+1);
      
    } else if (a % 10 == 9) {
      lunlun.push_back(a*10+8);
      make_lunlun(a*10+8, n+1);
      lunlun.push_back(a*10+9);
      make_lunlun(a*10+9, n+1);
    } else {
      lunlun.push_back(a*10+(a%10));
      make_lunlun(a*10+(a%10), n+1);
      lunlun.push_back(a*10+(a%10)-1);
      make_lunlun(a*10+(a%10)-1, n+1);
      lunlun.push_back(a*10+(a%10)+1);
      make_lunlun(a*10+(a%10)+1, n+1);
    }
  } 
}

int main() {
  int K;
  cin >> K;
  
  for (ll i = 1; i <= 9; i++) {
    make_lunlun(i, 1);
  }
  
  sort(lunlun.begin(), lunlun.end());
  
  cout << lunlun[K-1] << endl;
  
  
}