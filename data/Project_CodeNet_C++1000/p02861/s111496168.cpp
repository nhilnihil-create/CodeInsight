
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
#include <regex> //正規表現
using namespace std;
#define _GLIBCXX_DEBUG /GCC環境下で[]による配列要素参照のエラーを出す
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end() //sort(all(vec)); ,reverse(all(vec));etc
int main(){
  int n;
  cin>>n;
  vector<int>vec(n);
  rep(i,n){
    vec.at(i)=i;
  }
  vector<vector<int>>pos(n,vector<int>(2));
  int x,y;
  rep(i,n){
    cin>>x>>y;
    pos[i][0]=x;
    pos[i][1]=y;
  }
  int b=1;
  double d=0;
  rep(i,n){
    b*=(i+1);
  }
  do{
    rep(i,n-1){
      d+=sqrt(pow((pos[vec.at(i)][0]-pos[vec.at(i+1)][0]),2)+pow((pos[vec.at(i)][1]-pos[vec.at(i+1)][1]),2));
    }
  }while (next_permutation(vec.begin(), vec.end()));
  cout<<fixed<<setprecision(10);
  cout<<d/b<<endl;
}

  