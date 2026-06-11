#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
//using P = pair<int,int>;


int main(){
 int n,m,b=0,a=0;
  cin >> n >> m;
  rep(i,m){
    cin >> a;
    b += a;
  }
  if(n>=b) cout << n-b << endl;
  else cout << -1 << endl;
}