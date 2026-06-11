#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  string S;
  cin>>S;
  map<int,int>mp;
  map<char,int>mp1;
  map<int,int>mp2;
  for(int i=0;i<N;i++){
    if(mp1[S.at(i)]==1) continue;
    mp1[S.at(i)]++;
    for(int j=i+1;j<N;j++){
      if(mp2[(S.at(i)-'0')*10+(S.at(j)-'0')]==1) continue;
      mp2[(S.at(i)-'0')*10+(S.at(j)-'0')]++;
      for(int k=j+1;k<N;k++){
        mp[(S.at(i)-'0')*100+(S.at(j)-'0')*10+(S.at(k)-'0')]++;
      }
    }
  }
  cout<<mp.size()<<endl;
  return 0;
}

