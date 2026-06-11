#include<bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (int)n; i++)

int main(){
  int n,k;
  cin >> n >> k;
  int i = 0;
  while (pow(k,i) <= n) {
    i++;
  }
  cout << i << endl;
}
