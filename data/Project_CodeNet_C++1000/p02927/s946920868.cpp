#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  int m, d;cin>>m>>d;
  int result=0;
  rep(i, m)rep(j, d){
    if((j+1)%10<2 || (j+1)/10<2)continue;
    if( ( ((j+1)%10)*((j+1)/10) )==( i+1 ) )result++;
//    if( ( ((j+1)%10)*((j+1)/10) )==( i+1 ) )cout<<i+1<<' '<<j+1<<endl;
  }

  cout<<result<<endl;

  return 0;
}