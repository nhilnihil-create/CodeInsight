#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<queue>
#include<stack>
#include<map>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

template<typename A, typename B> bool chmin(A &a, const B &b){ return b < a && (a = b, true); }
template<typename A, typename B> bool chmax(A &a, const B &b){ return a < b && (a = b, true); }

int main(){
  long long a,v,b,w,t;
  cin >> a >> v >> b >> w >> t;
  if (a == b ){
    cout << "YES\n";
    return 0;
  }
  else if ((a > b && v * t - w * t >= a - b) || (a < b && v * t - w * t >= b - a)){
    cout << "YES\n";
  }
  else{
    cout << "NO\n";
  }
}