#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long int ll;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int a,b,k,m;
  string s,t;
  cin >>k>>a>>b;
  m=a/k;
  if(a%k!=0)m++;
  if(k*m>b){
    cout <<"NG";
  }else{
    cout <<"OK";
  }
}