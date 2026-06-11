#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define vi vector<int>
#define all(x) (x).begin(),(x).end()
using ll = long long;
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(b<a) { a=b; return 1; } return 0; }

int main(){
  int x; cin >> x;
  for(ll b = -150; b < 150; b++){
    for(ll a = b+1; a < 150; a++){
      if(a*a*a*a*a-b*b*b*b*b == x){
        cout << a << " " << b;
        return 0;
      }
    }
  }
  cout << "\n";
  return 0;
}
