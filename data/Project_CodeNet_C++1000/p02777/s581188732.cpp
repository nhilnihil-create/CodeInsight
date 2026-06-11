#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long int ll;
typedef unsigned long long int ull;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int a,b,c;
  string s,t,u;
  cin >>s>>t>>a>>b>>u;
  if(s==u){
    a--;
  }else{
    b--;
  }
  cout <<a<<' '<<b;
}