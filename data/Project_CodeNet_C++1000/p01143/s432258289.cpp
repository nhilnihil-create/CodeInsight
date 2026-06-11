#include <iostream>
#include <algorithm>
 
using namespace std;
 
main(){
  int n, m, p, sum, input[100];
  while(cin >> n >> m >> p && (n|m|p)){
    sum = 0;
    for(int i=0;i<n;i++){
      cin >> input[i];
      sum += input[i] * 100;
    }
    int ans = sum *(100-p) / 100;
    if(input[m-1]) ans /= input[m-1];
    else ans = 0;
    cout << ans << endl;
  }
  return 0;
}
