#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef std::pair<int,int> pair2;
typedef std::pair<int,pair2> pair3;
const ll INF = 1LL<<60;

int main(){
ll W,H;
ll x,y;
  cin>>W>>H>>x>>y;
 //ll ans;
  
  if(W%2==1&&H%2==1){
  cout<<W*H/2+0.5<<" ";
  }
else{
cout<<W*H/2<<" ";
}
  
  if(2*x==W&&2*y==H){
    cout<<1<<endl;
  }
  else{
  cout<<0<<endl;
  }
  

  
  
  
  
}
