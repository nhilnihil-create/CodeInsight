#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)n; ++i)
using namespace std;
using ll = long long;

int main(){
  int n,d;
  cin >> n >> d;
  cout << (n + (d*2+1) - 1) / (d*2+1) << endl;
}
