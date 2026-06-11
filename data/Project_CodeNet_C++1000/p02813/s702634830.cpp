
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
  vector<int>p(n);
  rep(i,n){
    cin>>p.at(i);
  }
  vector<int>q(n);
  rep(i,n){
    cin>>q[i];
  }
  vector<int>vec(n);
  rep(i,n){
    vec[i]=i+1;
  }
  int cnt =0;
  int pp,qq;
  pp=0;
  qq=0;
  do{
    //cout<<vec[0]<<vec[1]<<vec[2]<<endl;
    if(vec==p){
      pp=cnt;
    }
    if(vec==q){
      qq=cnt;
    }
    if(pp!=0&&qq!=0){
      break;
    }
    cnt+=1;
  }while(next_permutation(vec.begin(),vec.end()));
  //cout<<vec[0]<<vec[1]<<vec[2]<<endl;
  cout<<abs(pp-qq)<<endl;
}

  