#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,d;
  cin >> n >> d;
  int dis[n][d];
  for(int i = 0; i < n; i++){
    for(int j = 0; j < d; j++){
      cin >> dis[i][j];
    }
  }
  int ans = 0;
  for(int i = 0; i < n; i++){
    for(int j = i+1; j < n; j++){
      int count = 0;
      for(int p = 0; p < d; p++){
        int cnt = abs(dis[i][p] - dis[j][p]);
        count += cnt * cnt;
      }
      bool flag = false;
      for(int k = 0; k <= count; k++){
        if(k * k == count){
          flag = true;
        }
      }
      if(flag) ans++;
    }
  }
  cout << ans << endl;
}