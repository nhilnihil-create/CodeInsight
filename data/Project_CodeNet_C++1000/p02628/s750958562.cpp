#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,K;
  int a[1100];
  cin >> N >> K;
  for (int i=0;i<N;i++){
    cin >> a[i];
  }
  sort(a, a+N);
  int ans =0;
  for(int i=0;i<K;i++){
    ans += a[i];
  }
  cout << ans << endl;
  return 0;
}