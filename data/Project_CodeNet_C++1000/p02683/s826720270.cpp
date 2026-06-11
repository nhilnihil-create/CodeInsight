#include <iostream>
#include<vector>
using namespace std;
int main(void){
    int n,m,x;
    cin >> n >> m >> x;
    vector<vector<int>> a(n,vector<int>(m));
    vector<int> c(n);
    
    for(int i = 0;i < n;i++){
          cin >> c[i];
          for(int j = 0;j < m;j++){
                cin >> a[i][j];
          }
    }
    
    int ans = 1234567878;
    
    for(int i = 0;i < 1 << n;i++){
          int t = 0;
          bool ok = true;
          vector<int> level(n);
          for(int j = 0;j < n;j++){
                if(i >> j & 1){
                      for(int k = 0;k < m;k++){
                            level[k] += a[j][k];
                      }
                      t += c[j];
                }
          }
          for(int j = 0;j < m;j++){
                if(level[j] < x)ok = false;
          }
          if(ok){
                ans = min(ans,t);
          }
          
          
    }
    if(ans == 1234567878){
          cout << -1 << endl;
    }else{
          cout << ans << endl;
    }
}
