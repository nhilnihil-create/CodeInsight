#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define ll long long 

int main() {
  int n;
  cin >> n;
  vector<vector<int>> a(n+1);
  int tmp;
  for(int i = 1;i<n+1;i++){
    for(int j = 0;j<n-1;j++){
      cin >> tmp;
      a[i].push_back(tmp);
    }
  }
  int c = n*(n-1)/2;
  ll day = 0;
  int t;
  int flg = 0;
  int upd = 0;
  while(c >0){
    upd = 0;
    int used[n+1] = {};
    for(int i = 1;i<n+1;i++){
      t = a[i][0];
      if(a[i].size() > 0 && a[t].size() >0){
        if(used[i] == 0 && used[t] == 0 && a[t][0] == i ){
          a[i].erase(a[i].begin());
          a[t].erase(a[t].begin());
          used[i] = 1;
          used[t] = 1;
          c--;
          upd = 1;
        }
      }
    }
    if(upd == 0){
      flg = 1;
      break;
    }
    day++;
  }
  
  if(flg == 1){
    cout << -1;
  }else{
    cout << day;
  }
  
}