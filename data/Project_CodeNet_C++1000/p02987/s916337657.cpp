#include<bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin>>S;
  vector<char> fuga(4);
  for(int i=0; i<4; i++){
    fuga[i]=S[i];
  }
  sort(fuga.begin(),fuga.end());
  int cnt=0;
  for(int i=0; i<3; i++){
    if(fuga[i]==fuga[i+1]){
      cnt++;
    }
  }
  cout<<(cnt==2?"Yes":"No");
}
       
           