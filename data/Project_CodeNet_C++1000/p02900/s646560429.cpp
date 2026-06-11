#include<bits/stdc++.h>
#define ll long long int
 
using namespace std;
 
const ll mod=1000000007;
const ll inf=1e18;
 
ll gcd(ll a,ll b){
  if(a%b == 0){
    return b;
  }else{
    return gcd(b, a%b);
  }
}
 
vector<ll> soinsu(ll a){//素因数分解する。例:soinsu(60)={2,2,3,5}
  if(a<=0) return {};
  if(a==1) return {1};
  vector<ll> f;
  ll b=a;
  for(ll i=2;i*i<=a;i++){
    if(b%i==0){
      f.push_back(i);
      b=b/i;
      i--;
    }
  if(b==1)break;
  }
  if(b!=1)f.push_back(b);
  return f;
}
 
int main(){
 
  ll a,b;
  cin >> a >> b;
  //gcd(a,b)の素因数の数を数えたい(1に注意する)
  ll d=gcd(a,b);

  
 
  vector<ll> v=soinsu(d);
  //vは昇順になっているので、cを一番最近見た素数として、新しく見た素数がcと違うならs++してcを更新。
  ll c=1;//1を考慮して初期値はc=s=1
  ll s=1;
  for(ll i=0;i<v.size();i++){
    if(v[i]!=c){
      c=v[i];
      s++;
    }
  }
  // set<ll> u;
  // for(int i=0;i<v.size();i++)u.insert(v[i]);
  // cout << u.size()+1 << endl;
  cout << s << endl;

 
  // for(int i=0;i<v.size();i++)cout << v[i] << endl;
 
 
}