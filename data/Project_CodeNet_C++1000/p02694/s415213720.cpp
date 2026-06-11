#include <bits/stdc++.h>
using namespace std;

int main() {
  long long X;
  cin>>X;
  
  long long count=0,A=100;
  
    while(X > A){
      A += A/100;
      count++;
    }
   cout << count << endl;
  
}
 