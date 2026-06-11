#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REPLL(i, n) for (ll i = 0; i < (ll)(n); i++)
using namespace std;
template<class T>inline bool chmax(T &a, const T &b){if(a < b){a = b; return 1;}return 0;}
template<class T>inline bool chmin(T &a, const T &b){if(a > b){a = b; return 1;}return 0;}
typedef long long ll;

// ABC147 A - Blackjack
// 2020.06.19

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int A1, A2, A3; cin >> A1 >> A2 >> A3;
  if(A1+A2+A3 >= 22){
    cout << "bust" << endl;
  }else{
    cout << "win" << endl;
  }
}