#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
  int n;
  while(true){
    cin >> n;
    if(n == 0)
      break;

    vector<bool> hurui(2*n + 1, true);
    int root = sqrt(2*n) + 1;
    for(int i=2; i<=2*n; i++){
      if(hurui[i] == true){
        for(int j=2*i; j<=2*n; j+=i){
          hurui[j] = false;
        }
      }
    }
    
    int ans = 0;
    for(int i=1; i<=n; i++){
      if(hurui[n+i] == true){
        ans++;
      }
    }
    cout << ans << endl; 
  }
  
  return 0;
}