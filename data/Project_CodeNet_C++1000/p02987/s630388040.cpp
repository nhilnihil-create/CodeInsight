#include <bits/stdc++.h>
using namespace std;

int main(){
  map<char,int> S;
  for(int i=0;i<4;i++){
    char c;
    cin>>c;
    S[c]++;
  }
  for(pair<char,int> i:S)
    if(i.second!=2){
      cout<<"No"<<endl;
      return 0;
    }
  cout<<"Yes"<<endl;
}