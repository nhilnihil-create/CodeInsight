#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,m;
  int smallA = 100000;
  int smallB = 100000;
  int smallWariNasi = 0;
  int smallWari = 200000;
  
  cin >> a >> b >> m;
  vector<int> vecA(a);
  vector<int> vecB(b);
  
  for(int i = 0; i < a; i++){
    cin >> vecA.at(i);
    if(smallA > vecA.at(i)) smallA = vecA.at(i);
  }
  for(int i = 0; i < b; i++){
    cin >> vecB.at(i);
    if(smallB > vecB.at(i)) smallB = vecB.at(i);
  }
  
  smallWariNasi = smallA + smallB;
  
  int tmpA,tmpB,wariKin;
  for(int i = 0; i < m; i++){
    cin >> tmpA >> tmpB >> wariKin;
    tmpA--;
    tmpB--;
    if(smallWari > vecA.at(tmpA) + vecB.at(tmpB) - wariKin){
      smallWari = vecA.at(tmpA) + vecB.at(tmpB) - wariKin;
    }
  }
  
  if(smallWariNasi <= smallWari) cout << smallWariNasi;
  else cout << smallWari;
}
