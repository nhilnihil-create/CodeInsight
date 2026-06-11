#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using ll=long long;
using namespace std;
int main(){
  ll n;
cin>>n;
  string res;
  while(1){
  res+=(char)('a'+((n-1)%26));//aから、(n-1)%26個分シフト
  n=(n-1)/26;//n-1を26で割った商を代入する
  if(n==0) break;//割った商が0ならbreak
  }
  reverse(res.begin(),res.end());//最初と最後を逆転させる
  cout<<res<<endl;
}
