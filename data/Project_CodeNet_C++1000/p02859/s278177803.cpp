#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>
#include<iostream>
using namespace std;
long long int lcm(long long int a,long long int b){
  long long int n;
  n=a*b/__gcd(a,b);
  return n;
}
using ll =long long int;
#define ci(a) cin>>a
#define co(a) cout<<a<<endl
#define gcd(a,b) __gcd(a,b)
#define vec vector<ll>
#define For(i,a,b) for(ll i=a;i<b;i++)
#define rFor(i,a,b) for(ll i=a;i>b;i--)
#define wFor(i,a,b) for(ll i=a;i<b;i+=2)
#define wrFor(i,a,b) for(ll i=a;i>b;i-=2)
#define sort(a,b) sort(a.begin(),b.end())
#define reverse(a,b) reverse(a.begin(),b.end())
//gcd 最大公約数
//lcm 最小公倍数
//double 少数（変数）
//string 文字列（変数）
//sqrt 平方根
//ceil 天井関数
//floor 床関数
//abs 絶対値
//pow 累乗
//cbrt  立方根
//hypot 平方和の平方根
//(string-'0') 文字列を数字に変換
//(char-'0') 数字に変換
//vector<vector<int>> data(a,vector<int>(b)) a×b行列
//for(int i=0;i<a;i++)
//for(int j=0;j<b;j++)
//cin>>data.at(i).at(j)  a×b行列の入力
//floor(log10(a)+1) aの10進法での桁数
//ceil(log10(a)) aの10進法での桁数

int main() {
  ll a;
  ci(a);
  co(a*a);
}