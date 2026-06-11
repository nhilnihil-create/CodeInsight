#include<bits/stdc++.h>
using namespace std;

int main(){
  int m, d;
  cin>>m>>d;

  int c=0;
  for(int i=22;i<=d;i++){
     if((i%10)>=2 && (i/10)*(i%10)<=m)c++;
  }
  cout<<c;
}
