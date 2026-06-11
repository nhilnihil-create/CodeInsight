#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < n; i++) 
using namespace std;
typedef long long ll;

int main() {
  
  int k, x;
  cin >> k >> x;
  
  REP(i,k*2-1) { 
    cout << x-k+i+1 << " ";
  }

}