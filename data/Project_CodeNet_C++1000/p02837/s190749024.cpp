#include <iostream>
#include<vector>
using namespace std;
int main(void){
    int n;
    cin >> n;
    vector<vector<int>> g(n,vector<int>(n,-1));
    
    for(int i = 0;i < n;i++){
          int a;
          cin >> a;
          for(int j = 0;j < a;j++){
                int x,y;
                cin >> x >> y;
                x--;
                g[i][x] = y;
          }
    }
    
    int ans = 0;
    
    for(int i = 0;i < 1 << n;i++){
          bool ok = true;
          int t = __builtin_popcount(i);
          
          for(int j = 0;j < n;j++){
                if(i >> j & 1){
                      for(int k = 0;k < n;k++){
                            if(g[j][k] == -1)continue;
                            if(g[j][k] != (i >> k & 1)){
                                  ok = false;
                            }
                      }
                }
          }
          if(ok)ans = max(ans,t);
    }
    cout << ans << endl;
    
}
