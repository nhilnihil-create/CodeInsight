#include <bits/stdc++.h>
#define rep(i,n) for(int i=1; i<=(n); ++i)
#define PI 3.14159265359
using namespace std;
using ll = long long;

int main(){
  int n;
  cin >> n;
  ll m=0;
  rep(i,n){
    if(i%3==0 || i%5==0) continue;
    m += i;
  }
  cout << m << endl;
  return 0;
}
