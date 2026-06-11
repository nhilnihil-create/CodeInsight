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
#include <regex>
using namespace std;
#define _GLIBCXX_DEBUG 
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end() //sort(all(vec)); ,reverse(all(vec));etc
int main(){
    int n;
    cin>>n;
    uint64_t ans;
    vector<uint64_t>a(100000);
    ans=1;
    uint64_t k=1;
    rep(i,18){
        k*=10;
    }
    //cout<<k<<endl;
    rep(i,n){
       cin>>a.at(i);
       if(a.at(i)==0){
           cout<<0<<endl;
           return 0;
       }
    }
    rep(i,n){
        if(a.at(i)>k/ans){
            
            cout<<-1<<endl;
            return 0;
        }else{
            ans=ans*a.at(i);
        }
    }
    cout<<ans<<endl;
}

