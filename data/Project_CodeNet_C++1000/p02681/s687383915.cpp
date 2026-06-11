#include <bits/stdc++.h>
using namespace std;
 
int main()
{
  string a,b;
  cin>>a;
  cin>>b;
  int c;
  int i=0;
  int flag=0;
  c=a.size();
  while(i<c){
    if(a.at(i)!=b.at(i)){
      flag=1;
    }
    i++;
  }
  if(flag==1){
    cout<<"No";
  }else{
    cout<<"Yes";
  }
}