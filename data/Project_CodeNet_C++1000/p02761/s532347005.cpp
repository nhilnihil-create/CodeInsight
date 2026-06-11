#include<bits/stdc++.h>
#define rep(i,f,n) for(ll i=(f); (i) < (n); i++)
#define repe(i,f,n) for(ll i=(f); (i) <= (n); i++)
using namespace std;
using ll = long long;

ll INF = 1LL << 60;

int 
main() {

  int N, M; cin >> N >> M;
  vector<int> arr(N, -1);

  rep(i, 0, M){
    int digit; cin >> digit, --digit;
    int value; cin >> value;
    if(arr[digit] != -1){
      if(value != arr[digit]){
        cout << -1 << endl;
        return 0;
      }
    }
    if(N > 1 && digit == 0 && value == 0){
      cout << -1 << endl;
      return 0;
    }
    arr[digit] = value;
  }

  if(N == 1){
    if(arr[0] != -1) cout << arr[0];
    else cout << 0 << endl;
    return 0;
  } else if(arr[0] != -1) {
    cout << arr[0];
  } else {
    cout << 1;
  }

  rep(i, 1, N){
    if(arr[i] != -1){
      cout << arr[i];
    } else {
      cout << 0;
    }
  }
  cout << endl;
}
