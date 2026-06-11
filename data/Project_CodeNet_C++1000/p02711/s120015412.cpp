#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  for(int i=0;i<3;i++){
    //cout<<s.at(i)<<endl;
    if(s[i]=='7'){
      cout<<"Yes"<<endl;
      goto OUT;
    }
  }
  cout<<"No"<<endl;
  OUT:;
}