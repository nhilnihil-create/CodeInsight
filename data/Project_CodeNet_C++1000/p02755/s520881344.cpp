#include<bits/stdc++.h>
#define rep(i,n) for (ll i =0; i <(n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
  double A, B;
  cin >> A >> B;
  for(int i= 1; i <= 1009; i++){
    double x = i * 0.08;
    double y = i * 0.1;
    if( (int)x == A && (int)y == B ){
      cout << i << endl;
      return 0;
    }
  }
  cout << -1 << endl;
}