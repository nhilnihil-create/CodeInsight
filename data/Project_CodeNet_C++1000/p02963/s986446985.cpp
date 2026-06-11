#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rng(a) a.begin(),a.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
const int num = 1e9;


int main() {
  ll n;
  cin >> n;
  int x = (num-n%num)%num;
  int y = (n+x)/num;
  printf("0 0 %d 1 %d %d \n", num, x, y);
  return 0;
}