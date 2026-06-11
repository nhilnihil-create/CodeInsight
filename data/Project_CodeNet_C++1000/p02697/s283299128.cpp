#include <bits/stdc++.h>
using namespace std;
// それぞれのスタジアムの間隔が異なるように配置すればよい
// (Nが偶数のときは,間隔がN/2にならないようにケア)

int main(){
  int N,M;
  cin >> N >> M;

  int Mremain= M;
  int lower= N/2;
  int upper= lower+ 1;
  while(Mremain > 0){
    if(N==2*(upper- lower) || N==2*(upper- lower- 1)){ upper++; }

    cout << lower <<" "<< upper << endl;
    lower--; upper++;
    Mremain--;
  }
}