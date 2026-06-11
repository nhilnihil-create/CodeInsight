#include<bits/stdc++.h>
using namespace std;
 
int main() {
  int n,a;
  cin >> n;
  for(int i=0;i<n;i++){
    cin >> a;
    if(a%2!=0)	continue;
    else{
      if(a%3==0)	continue;
      else if(a%5==0)	continue;
      else{
        cout << "DENIED";
        return 0;
      }
    }
  }
  cout << "APPROVED";
  return 0;
}
