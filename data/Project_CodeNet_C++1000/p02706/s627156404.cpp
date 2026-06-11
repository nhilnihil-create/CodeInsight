#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
int main() {
  int n, m;
  cin >> n >> m;
  int a[m];
  int d = 0;
  int i;
  rep(i, m){
    cin >> a[i];
  	d += a[i]; 
  }
  int p;
  p = n - d;
  if(p >= 0)
    cout << p << endl;
  else
    cout << "-1" << endl;
}