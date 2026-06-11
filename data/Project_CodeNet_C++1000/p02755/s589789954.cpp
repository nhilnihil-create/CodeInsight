
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
  int a,b;
  cin>>a>>b;
  for(int i=1;i<1250;i++){
    //cout<<i<<" "<<(int)(i*0.08)<<" "<<(int)(i*0.1)<<endl;
    if((int)(i*0.08)==a&&(int)(i*0.1)==b){
      cout<<i<<endl;
      return 0;
    }
  }
  cout<<-1<<endl;
}