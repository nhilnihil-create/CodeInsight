#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,k;
  cin >> n >> k;
  vector<int> ls(n,0);
  for (int i = 0; i < k; i++){
    int d;
    cin >> d;
    for (int j = 0; j < d; j++){
      int a;
      cin >> a;
      ls.at(a-1)++;
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++){
    if (ls.at(i) == 0){
      ans++;
    }
  }
  cout << ans << endl;
}