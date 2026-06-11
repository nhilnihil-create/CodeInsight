#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;

int main(void){
    int x,n;
    cin >> x >> n;
    vector<int> v(102,1);
    for(int i = 0;i < n;i++){
          int a;
          cin >> a;
          v[a] = 0;
    }
    int ans = 0;
    int t = 102;
    for(int i = 0;i < 102;i++){
          if(v[i]){
              if(t > abs(x - i)){
                    t = abs(x - i);
                    ans = i;
              }  
          }
    }
    cout << ans << endl;
}
