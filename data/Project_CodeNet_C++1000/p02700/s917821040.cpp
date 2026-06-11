#include<bits/stdc++.h>
using namespace std;

int main(){
  int ta,th,aa,ah;
  cin >> th >> ta >> ah >> aa;
  int c=0;
  while(th>0&&ah>0){
    if(c%2==0)
      ah-=ta;
    else
      th-=aa;
    c++;
  }
  cout << (th>0?"Yes":"No") << endl;
  return 0;
}