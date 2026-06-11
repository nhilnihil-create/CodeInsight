#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep1(i, n) for(int i = 1; i < n+1; i++)
#define all(A) A.begin(),A.end()
typedef long long ll;

int main(){
  int x;
  cin >> x;
  int c = x/100;
  if(c*100 <= x && x <= 105*c) cout << 1 << endl; 
  else cout << 0 << endl;
}