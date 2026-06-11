#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, k;
  cin >> n >> k;
  vector< int > arr(n,1);
  int ans = n;
  int d;
  int x;
  for(int i = 0;  i < k ; ++i){
    cin >> d;
    for(int j = 0; j< d; ++j){
      cin >> x;
      if(arr[x-1] == 1){
        ans--; arr[x-1]--;
      }
    }
  }
  cout << ans << '\n';
}