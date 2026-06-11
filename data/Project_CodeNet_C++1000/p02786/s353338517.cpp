/*そーなのかー
　　　＿
　 '´　　 ヽ
 ./ ﾉﾉ））)）〉
〈《.! ﾟ ヮﾟﾉ》
　⊂!::V::!つ
　 く::::::::〉
　　 し'ﾉ*/
#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  long long p=1;
  for(int i=0;i<n;i++){
    p*=2;
    if(p>n){
      break;
    }
  }
  cout << p-1 << endl;
}
