#pragma optimize("O3")
#include <bits/stdc++.h>

#define f(i,a,b)    for(int i = a; i < b; i++)
#define pb push_back
#define F first
#define S second
#define ii pair<int, int>

using ll = long long;
using db = long double;

using namespace std;
const int N = 1e6 + 5;
int get(int x){
  int ans = 0;
  for(int j = 1; x >= j; x -= j, j++)
    ans++;
  return ans;
}
int calc(ll x){
  int ans = 0;
  for(ll i = 2; i * i <= x; i++)
  if(x % i == 0){
    int c = 0;
    while(x%i==0){
      c++;
      x/=i;
    }
    ans += get(c);
  }
  return ans + (x > 1);
}

int main(){

    ll x; cin >> x; cout << calc(x) << endl;

    return 0;
}
