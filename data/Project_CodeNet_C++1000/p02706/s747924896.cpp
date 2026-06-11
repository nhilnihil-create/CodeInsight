#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;

int main(){
  ll n, m, a;
  cin >> n >> m;

  rep(i, m){
    cin >> a;
    n-=a;
  }

  if(n<0){
    cout << "-1" << endl;
  }
  else{
    cout  << n << endl;
  }

  return 0;
}