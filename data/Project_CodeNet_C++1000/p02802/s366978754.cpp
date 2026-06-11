
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
// set<int>st{ 3,1,4,1,5,9,2,6,5,3,5 };
//     for (auto itr = st.begin(); itr != st.end(); ++itr) {
//         cout << *itr;
//     }
#include <bits/stdc++.h>
#include <regex>
using namespace std;
#define _GLIBCXX_DEBUG 
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end() //sort(all(vec)); ,reverse(all(vec));etc
int main(){
  int n,m;
  cin>>n>>m;
  vector<vector<int>>vec(n,vector<int>(2));
  int p;
  string s;
  rep(i,m){
    cin>>p>>s;
    if(s=="AC"){
      vec.at(p-1).at(0)=1;
    }else{
      if(vec.at(p-1).at(0)==0){
         vec.at(p-1).at(1)+=1;
      }
      }
    }
  int ac,wa;
  ac=0;
  wa=0;
  rep(i,n){
   ac+=vec.at(i).at(0);
   if(vec.at(i).at(0)==1){
   wa+=vec.at(i).at(1);}
  }
  cout<<ac<<" "<<wa<<endl;
  }