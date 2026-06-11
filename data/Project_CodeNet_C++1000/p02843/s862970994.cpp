#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int main(void){
      int n;
      cin >> n;
    int a[6] = {100,101,102,103,104,105};
    vector<bool> x(1e5 + 1,false);
    x[0] = true;
    for(int i = 0;i < 6;i++){
          for(int j = 0;j <= 1e5;j++){
                if(x[j] && j + a[i] <= 1e5){
                      x[j + a[i]] = true;
                }
          }
    }
    cout << ((x[n]) ? 1 : 0) << endl;
    
}
