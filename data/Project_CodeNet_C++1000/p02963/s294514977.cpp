#include <bits/stdc++.h>
using namespace std;
using ll=unsigned long long;
/*
すごいでかい素数きた場合困る
  x
x
 x
4-1-(1/2)-1=3/2
超でかい長方形つくって、面積-1とか可能。
もし2で割り切れるなら、そのまま作るとか
ルートでとらな
9999とか
100^100

0,0, 0,100, 99,99で9999になる
10^18のルートは10^9かかるから無理
abs(x2*y3-x3*y2)=S
abs(
*/
int main(){
  ll S,z=1e9; cin>>S;
  if(S==1e18){
    cout<<"0 0 0 1000000000 1000000000 1000000000"<<endl;
    return 0;
  }
  ll y=S/z+1;
  ll x=z-S%z;
  cout<<"0 0 "<<z<<" "<<1<<" "<< x<<" "<<y<<endl;
}