#include <bits/stdc++.h>

using namespace std;

int main(){

  string S;
  string T;
  cin>>S>>T;
  int cnt=0;
  int cnt_max=0;

  for(int i=0; i<=S.size()-T.size(); i++){
    cnt=0;
    for(int j=0; j<T.size(); j++){
      if(S[i+j]==T[j]) cnt++;
    }
    cnt_max=max(cnt_max, cnt);
  }

  cout<<T.size()-cnt_max<<endl;
}
