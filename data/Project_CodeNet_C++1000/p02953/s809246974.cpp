#include<bits/stdc++.h>
#define rep(i,f,n) for(ll i=(f); (i) < (n); i++)
#define repe(i,f,n) for(ll i=(f); (i) <= (n); i++)
using namespace std;

typedef long long ll;
ll INF = 1LL << 60;
ll MAX = 100010;
ll MOD = 2019;

int
main() 
{
  int n; cin >> n;
  vector<ll> arr(n);
  rep(i, 0, n){
    cin >> arr[i];
  }

  if(n == 1){
    cout << "Yes" << endl;
    return 0;
  } else if(n == 2){
    if(arr[0] - 1 <= arr[1]){
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
    return 0;
  }

  bool flag = true;
  arr[0] -= 1;
  repe(i, 1, n - 1){
    if(arr[i - 1] < arr[i]) arr[i] -= 1;
    if(arr[i - 1] > arr[i]){
     flag = false;
    }
  }

  if(flag) cout << "Yes" << endl;
  else cout << "No" << endl;
}

