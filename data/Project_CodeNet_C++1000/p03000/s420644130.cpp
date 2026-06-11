#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,x;
  cin >> n >> x;
  vector<int> p(n);
  for(int i = 0; i < n; i++){
    cin >> p[i];
  }
  int d = 0;
  int ans = 1;
  for(int i = 0; i < n; i++){
    d += p[i];
    if(d > x){
      cout << ans << endl;
      return 0;
    }
    ans++;
  }
  cout << ans << endl;
}