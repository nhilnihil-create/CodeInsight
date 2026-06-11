

#include <bits/stdc++.h>
using namespace std;
 
int main() {
long long L,R;
  cin >> L >> R;
  int result = 2019;
  if((L / 2019) < (R / 2019)){
   cout << 0 << endl; 
  }else{
    for(long long a = L;a < R;a++){
      for(long long b = a + 1;b <= R;b++){
        if(result > (a * b) % 2019)result = (a * b) % 2019;
        
      }


    }
    cout << result << endl; 
  }
  
}