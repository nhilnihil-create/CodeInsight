#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

int main(){
  int n, k;
  cin >> n >> k;

  int cnt = 0;

  vector<int> h(n);
  rep(i,n){
    cin >> h[i];
    if(h[i]>=k)
      cnt++;
  }

  cout << cnt << endl;

  return 0;
}
