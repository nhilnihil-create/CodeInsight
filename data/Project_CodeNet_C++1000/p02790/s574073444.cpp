#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A,B;
  cin >> A >> B;
  int Max,mini;
  Max=max(A,B);
  mini=min(A,B);
  for(int i=0;i<Max;i++){
    cout << mini;
  }
  cout << endl;
}