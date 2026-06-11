#include <iostream>
#include <string>
#include<vector>
#include<algorithm>

using namespace std;
using ll = long long;

int main(void){

   ll n, a, b;

   cin >> n >> a >> b;

   //２人の距離が近い場合(偶数)
   if((b-a)%2==0){
      ll cnt_div = (b - a) / 2;
      cout << cnt_div << endl;
      return 0;
   }

      //ここから奇数

      //卓１まで移動してから出会う+1戦して調整する
      ll cnt1 = a; //１卓＋１戦

      //卓Nまで移動してから出会う＋1戦して調整する
      ll cntN = n - b + 1;

      ll meet = (b - a - 1) / 2;

      cout << min(cnt1, cntN) + meet << endl;

      return 0;
}
