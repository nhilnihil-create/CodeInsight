#include<bits/stdc++.h>
using ll=long long;
using namespace std;
#define rep(i, n) for(ll i=0; i<n; i++)
#define Rep(i, j, n) for(ll i=j; i<n; i++)
#define all(vec) vec.begin(), vec.end()
template<class T> inline bool chmin(T& a, T b) {if(a > b) {a = b; return true;} return false;}
template<class T> inline bool chmax(T& a, T b) {if(a < b) {a = b; return true;} return false;}

int main(){
  int n;
  cin>>n;
  int a=100*n/108;
  if(a*108/100==n)cout<<a<<endl;
  else if((a+1)*108/100==n)cout<<a+1<<endl;
  else cout<<":("<<endl;

  return 0;
}
