#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using ll=long long;
using namespace std;
int main(){
  ll a;
    double b;
cin>>a>>b;
  ll ib=100*b+0.5;//一旦bを100倍 doubleからllの変換で微妙な誤差が切り捨てられる？
//  cout<<ib<<endl;
  a*=ib;//整数同士で演算
  a/=100;//1/100で元に戻す
  cout<<a<<endl;
}
  
