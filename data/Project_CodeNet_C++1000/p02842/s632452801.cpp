#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n;
  cin >> n;
 
  int i=1;
  while(i<50001){
    if(n <= i*1.08 && i*1.08 < n+1){
      cout << i << endl;
      break;
    }
    i++;
  }
  
if(i==50001){
  cout << ":(" << endl;
}

}
