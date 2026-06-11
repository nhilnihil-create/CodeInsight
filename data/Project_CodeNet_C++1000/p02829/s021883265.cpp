#include<bits/stdc++.h>
using namespace std;

int main(){
  int a,b;
  vector<bool>exist(3);
  for(int i=0;i<3;i++)exist[i]=true;
  cin>>a;
  exist[a-1]=false;
  cin>>b;
  exist[b-1]=false;
  
  for(int i=0;i<3;i++)
    if(exist[i]==true)cout<<i+1<<endl;
  
  
  return 0;
}