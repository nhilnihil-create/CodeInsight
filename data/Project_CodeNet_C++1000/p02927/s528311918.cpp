#include<bits/stdc++.h>
using namespace std;
#define rep(j,n) for(int i=(int)(j);i<=(int)(n);i++)
int main(){
  int M,D;
  cin>>M>>D;
  int count=0;
  if(D>=22){
  rep(22,D){ 
    if(1<=(i%10)*(i/10)&&(i%10)*(i/10)<=M&&i%10>=2) count++;
  }
}
  else count=0;
  cout<<count<<endl;
}