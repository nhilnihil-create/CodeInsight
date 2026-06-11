#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int>a(N);
  for(int i=0; i<N; i++)cin >> a.at(i);
  
  int count = 1;
  int ans = 0;
  
  for(int i=0; i<N; i++){
    if(a.at(i)==count)count++;
    else ans ++;
  }
  
  if(ans==N)ans=-1;
  cout << ans << endl;
}