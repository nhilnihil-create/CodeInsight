#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;

int main(){
  float n, d;
  cin >> n >> d;
  float guardedArea = (d + d) + 1.0;
  cout << ceil(n / guardedArea) << endl;
}