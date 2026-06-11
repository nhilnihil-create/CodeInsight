#include <bits/stdc++.h>
using namespace std;
 
int main(void){
  string S = "1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51";
  int K;
  cin >> K;
  int count = 0;
  int n = 1;
  while(count < S.length()){
   if(S[count] == ',' && S[count + 1] == ' '){
     count += 2;
     n++;
   }
    else if(n == K) {
      cout << S[count];
      count++;
    }
    else count++;
  }
  
  return 0;
}
