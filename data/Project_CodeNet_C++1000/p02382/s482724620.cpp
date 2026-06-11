
//auto 関数名 = [(&:ラムダ外の引数をとる時))](引数の型1 引数名1, 引数の型2, 引数名2, ...) { 関数の処理 }; //inside main() define function. take care of };
// for (int tmp = 0; tmp < (1 << ビット数); tmp++) {
//   bitset<ビット数> s(tmp);
//   // (ビット列sに対する処理)
// }
// sort(配列変数.begin(), 配列変数.end());
// do {
//   // 順列に対する処理
// } while (next_permutation(配列変数.begin(), 配列変数.end()));
//const double PI = acos(-1); M_PI
// cout << fixed << setprecision(10);
#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG /GCC環境下で[]による配列要素参照のエラーを出す
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end() //sort(all(vec)); ,reverse(all(vec));etc
double cbrt_newton(double a,double x){
  double e;
  do{
    e=(x*x*x-a)/(3.0*x*x);
    x=x-e;

  }while(fabs(e)>1.0e-6);
  return x;
}
int main(){
int n;
cin>>n;
vector<int>vecx(n);
vector<int>vecy(n);
rep(i,n){
  cin>>vecx.at(i);
}
rep(i,n){
  cin>>vecy.at(i);
}
int md=0;
rep(i,n){
  md+=abs(vecx.at(i)-vecy.at(i));
}
cout<<fixed<<setprecision(10);
cout<<md<<endl;
double yd=0;
rep(i,n){
  yd+=pow((vecx.at(i)-vecy.at(i)),2);
}
cout<<sqrt(yd)<<endl;
double yyd = 0;
rep(i,n){
  yyd+=pow(abs((vecx.at(i)-vecy.at(i))),3);
}
//1/3乗をニュートン法で実装
if(yyd==0){
  cout<<yyd<<endl;
}else{
yyd = cbrt_newton(yyd,sqrt(yd));
cout<<yyd<<endl;}
int cd=0;
rep(i,n){
 if(cd<(abs(vecx.at(i)-vecy.at(i)))){
   cd=abs(vecx.at(i)-vecy.at(i));
 }
}
cout<<cd<<endl;
}
