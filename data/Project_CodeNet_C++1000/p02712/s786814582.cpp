#include <bits/stdc++.h>
#include <string>
using namespace std;

int main(){
    int64_t n, ans = 0;
    cin >> n;
    
    for (int i = 1; i <= n; i++){
      if(i%3 != 0 && i%5 != 0) ans = ans + i;

    
    }
  cout <<  ans  << endl;
}