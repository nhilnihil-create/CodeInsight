#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep1(i, n) for(int i = 1; i < n+1; i++)
#define all(A) A.begin(),A.end()
typedef long long ll;

int main(){
  int x;
  cin >> x;
  rep(i,1000){
    if(100*i<=x && x<=105*i){
      cout << 1 << endl;
      return 0;
    }
  }
  cout << 0 << endl;
  return 0;
}