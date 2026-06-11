
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
  vector<bitset<15>>n1(n);
  vector<bitset<15>>n2(n);
  rep(i,n){
    bitset<15>t((1<<n)-1);
    n2.at(i)=t;
  }
  rep(i,n){
    int a;
    cin>>a;
    rep(j,a){
      int x,y;
      cin>>x>>y;
      n1.at(i).set(x-1,y);
      n2.at(i).set(x-1,y);
    }
  }
int ans=0;
int k;
  for(int tmp=0;tmp<(1<<n);tmp++){
    k=0;
    bitset<15>cnt(tmp);
    rep(i,n){
      //cout<<cnt<<endl;
      if(cnt.test(i)){
        //cout<<i<<" "<<cnt|n1.at(i)<<" "<<cnt&n2.at(i)<<endl;
        if((cnt|n1.at(i)).count()!=((cnt&n2.at(i)).count())){
          goto SKIP;
        }
      }
    }
    k=cnt.count();
    if(k>ans){
      ans=k;
    }
    SKIP:
    continue;
  }
cout<<ans<<endl;
}

  