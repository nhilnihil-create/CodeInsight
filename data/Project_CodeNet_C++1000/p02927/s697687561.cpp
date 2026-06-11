#include <bits/stdc++.h>
using namespace std;
int main(){
  int m,d,x=0;cin>>m>>d;
  for(int i=1;i<=m;i++)for(int j=1;j<=d;j++){
    if(j>20&&j%10>1&&(j%10)*(j/10)==i)x++;
  }
  cout<<x<<endl;
}