#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

int main(){
  int n, k;
  cin >> n >> k;
  int cnt = 0;
  int a;
  rep(i,n){
    cin >> a;
    if(a>=k)
      cnt++;
  }

  cout << cnt << endl;

  return 0;
}
