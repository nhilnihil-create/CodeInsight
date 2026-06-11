#include<bits/stdc++.h>
using namespace std;
int main(){
  int count=0;
  string S;
  cin>>S;
  for(int i=0;i<S.size();i+=2){
    if(S.at(i)!='R'&&S.at(i)!='U'&&S.at(i)!='D'){
      count++;
     // cout<<count<<endl;
    }
  }
   for(int i=1;i<S.size();i+=2){
    if(S.at(i)!='L'&&S.at(i)!='U'&&S.at(i)!='D'){
      count++;
    }
   }
  if(count==0) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}