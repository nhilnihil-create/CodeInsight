
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
  string s;
  cin>>s;
  string e;
  int ans=0;
  rep(i,10){
    //cout<<i<<" ";
    rep(j,10){
      //cout<<j<<" ";
      rep(k,10){
        //cout<<k<<endl;
        e=s;
        if(e.find(to_string(i))==string::npos){
          goto SKIPi;
        }else{//cout<<e<<" "<<e.find(to_string(k))<<endl;
          e=e.substr(e.find(to_string(i))+1);
          //cout<<e<<endl;
        }
        if(e.find(to_string(j))==string::npos){
          goto SKIPj;
        }else{//cout<<e<<" "<<e.find(to_string(j))<<endl;
          e=e.substr(e.find(to_string(j))+1);
         // cout<<e<<endl;
        }
        if(e.find(to_string(k))==string::npos){
          continue;
        }else{//cout<<e<<" "<<e.find(to_string(i))<<endl;
        //cout<<100*i+10*j+k<<endl;
        //cout<<e<<endl;
          ans+=1;
        }
      }
      SKIPj:;
    }
    SKIPi:;
  }
  cout<<ans<<endl;
}

  