#include <bits/stdc++.h>
using namespace std;
//型に気を付けよう
//a=0x61=97 '0'=0x30=48
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long  ll;
typedef long double  ld;
typedef string str;
typedef pair<int,int> pairii;
typedef vector<int> veci;
const double pi=3.1415926535;
const ll  mod=1000000007;
//桁数指定　cout << fixed << setprecision(2)
long long MAX(vector<int> Vec){//配列の最大値
  int n=Vec.size();
  int max= -2147483647;
  for(int i=0;i<n;i++){
    if(max<Vec.at(i))max=Vec.at(i);
  }
  return max;}
long long MAX2(vector<int> v){//配列の最大値
  int n=v.size();int p=MAX(v);
  int max= -2147483647;
  rep(i,n){if(v[i]==p)v[i]=-2147483647;}
  for(int i=0;i<n;i++){
    if(max<v.at(i))max=v.at(i);
  }
  return max;}
int num_cnt(veci v,int a){//ｖの中にint aはいくつ？
  int cnt=0;
  for(unsigned int i=0;i<v.size();i++){
    if(v[i]==a){  
   cnt++;
    }
  }
  return cnt;
}
int main() {
  int n;
  cin>>n;
  veci v(n);
  rep(i,n)cin>>v[i];
  int m=MAX(v);
  int m2=MAX2(v);
  int c=num_cnt(v,m)-1;
  cerr<<MAX2(v);
  rep(j,n){
   if(c){cout<<m<<endl;}
   else if(v[j]==m){cout<<m2<<endl;}
    else cout<<m<<endl;
  }
}