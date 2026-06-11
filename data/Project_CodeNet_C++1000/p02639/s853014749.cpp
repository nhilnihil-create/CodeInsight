#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
  pair<int,int>x;
  rep(i,5){
    cin>>x.first;
    x.second=i;
    if(x.first==0)cout<<i+1<<endl;
  }
  
  return 0;
}