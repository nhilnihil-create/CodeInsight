#include <bits/stdc++.h>
using namespace std;
 
int main() {
    long long  N;
    cin >> N;

    long long  count=0;
    for(;;){ 
      if(N==1){
          break;
      }
      N/=2;
      count++;
     }
 
     long long sum=0;
     for(int i=0;i<=count;i++){
         sum +=pow(2,i);
     }
     cout << sum << endl;
}