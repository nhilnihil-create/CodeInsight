#include <bits/stdc++.h>
using namespace std;
using ll=long long;
/*
目的地が深い人優先で配置
とちゅう追い抜きが必要かどうか。
追い抜ける場所があるか
...があれば追い抜き可能
CかD+1のちかいほうまでで抜けること。
#.C.は可能
遠いほうまでで、岩が2個並んでいないこと。
1WA
11 1 3 8 7  
...#.#...##
これか
あれ、別のがWAに
開始位置か
*/
int main(){
  ll N,A,B,C,D; cin>>N>>A>>B>>C>>D;
  string S; cin>>S;
  ll start1=min(A,B);
  ll start2=max(A,B);
  ll goal1=min(C,D);
  ll goal2=max(C,D);
  bool overtake=false;
  if((A-B)*(C-D)<0)
    overtake=true;
  for(int i=start1-1; i<goal2-1; i++){
    if(S[i]=='#' && S[i+1]=='#'){
      cout<<"No"<<endl;
      return 0;
    }
  }
  if(overtake){
    for(int i=start2-1; i<=goal1-1; i++){
      if(S[i-1]=='.' && S[i]=='.' && S[i+1]=='.') break;
      if(i==goal1-1){
        cout<<"No"<<endl;
        return 0;
      }
    }
  }
  cout<<"Yes"<<endl;
}