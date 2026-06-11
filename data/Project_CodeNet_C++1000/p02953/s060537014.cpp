#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define prtd(var, i) cout << fixed << setprecision(i) << var << endl;
#define ll long long
#define P pair<int, int>
using namespace std;

int main() { 
  int n;
  cin >> n;
  vector<ll> h(n);
  rep(i, n){
    cin >> h[i];
  }
  for(int i = n-1; i> 0; i--){
    //cout << h[i-1] << " " << h[i] << endl;
    if(h[i-1] > h[i]){
      h[i-1]--;
      if(h[i-1] > h[i]){
        cout << "No" << endl;
        return 0;
      }
    }
  }

  cout << "Yes" << endl;

}
