#include<bits/stdc++.h>
using namespace std;

int main(){
  int X;
  cin >> X;
  
  if(X < 100){
    cout << "0" << endl;
    return 0;
  }
  //した3桁だけ見ればあとは100で調整できる。
  int a = X % 1000; //3けただけ抽出
  int N = X /100;//100の位以上の数が選べる数
  int b = a % 100; //しも2桁
  int count = 0;
  while(b){ //ｂがゼロになるまで
    if(b-5 >= 0)b-=5;
    else if(b-4 == 0)b-=4;
    else if(b-3 == 0)b-=3;
    else if(b-2 == 0)b-=2;
    else if(b-1 == 0)b-=1;
    count++;
  }
  if(count <= N)cout << 1 << endl;
  else cout << 0 << endl;
}