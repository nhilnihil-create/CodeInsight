#include <bits/stdc++.h>
using namespace std;

int main(){
  int A, B, C, D;
  cin >> A >> B >> C >> D;
  vector<int> taka;
  int count1 = 0, count2 = 0;
  for(int i = 0; true; i++){    
    if(C <= 0) break;
    count1++;
    C = C - B;
  }
  vector<int> aoki;
  for(int i = 0; true; i ++){
    if(A <= 0) break;
    count2++;
    A = A - D;
  }
  if(count1 > count2) cout << "No" << endl;
  else cout << "Yes" << endl;
  return 0;
}