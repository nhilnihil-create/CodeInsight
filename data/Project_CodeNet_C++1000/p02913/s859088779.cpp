#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int N;
  string S;
  cin>>N>>S;
  int ok=0,ng=N/2+1;
  while(ng-ok>1){
    int n=(ok+ng)/2;
    set<string> s;
    for(int i=n;i+n<=N;i++){
      s.insert(S.substr(i-n,n));
      if(s.count(S.substr(i,n))){
        ok=n;
        goto home;
      }
    }
    ng=n;
    continue;
    home:;
  }
  cout<<ok<<endl;
}