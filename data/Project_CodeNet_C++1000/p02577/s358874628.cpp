#include<bits/stdc++.h>
using namespace std;
int main(){
  string S;cin>>S;
  long long count=0;
  for(int i=0;i<S.size();i++)count+=S.at(i)-'0';
  cout<<(count%9==0? "Yes":"No")<<endl;
}