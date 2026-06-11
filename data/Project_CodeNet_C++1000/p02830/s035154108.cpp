#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  string s,t;
  cin>>s>>t;
  string kk="";
  for(int i=0;i<N;i++){
    kk+=s[i];
    kk+=t[i];
  }
  cout<<kk<<endl;
}