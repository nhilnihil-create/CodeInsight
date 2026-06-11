#include<bits/stdc++.h>
using namespace std;
int main(){
 string s;cin>>s;
  int N=s.size();
  for(int i=0;i<N;i++)
    if(s.at(i)=='?')
      s.at(i)='D';
  cout<<s<<endl;
  return 0;
}