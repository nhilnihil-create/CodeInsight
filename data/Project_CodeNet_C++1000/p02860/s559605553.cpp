#include <bits/stdc++.h>
using namespace std;
#define rep(i,end) for(ll i = 0; i < end ; i++ )
typedef long long ll;
typedef vector<ll> vi;

int main() {
  int N;
  bool flag = true;
  cin >> N;
  string S;
  cin >> S;
  if (N%2 == 1){
    cout << "No" << endl;
  }
  else{
    rep(i, N/2){
      if (S[i] != S[i+N/2]){
        cout << "No" << endl;
        flag = false;
        break;
      }
    }
    if (flag){
      cout << "Yes" << endl;
    }

  }
}