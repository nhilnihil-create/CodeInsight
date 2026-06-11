#include <iostream>
#include<vector>
using namespace std;
int main(void){
    int n;
    cin >> n;
    vector<vector<int>> a(n,vector<int>(n,-1));
    
    for(int i = 0;i < n;i++){
          int A;
          cin >> A;
          for(int j = 0;j < A;j++){
                int x,y;
                cin >> x >> y;
                x--;
                a[i][x] = y;
          }
    }
    int ans = 0;
    for(int i = 0;i < 1 << n;i++){
          int t = __builtin_popcount(i);
          vector<int>v(n);
          for(int j = 0;j < n;j++){
                v[j] = i >> j &1;
            //     cout << v[j] << endl;
          }
          bool ok = true;
          for(int j = 0;j < n;j++){
                if(v[j]){
                      for(int k = 0;k < n;k++){
                            if(a[j][k] == -1)continue;
                            if(a[j][k] != v[k]){
                                  ok = false;
                            }
                      }
                }
          }
          if(ok)ans = max(ans,t);
          
    }
    cout << ans << endl;
}