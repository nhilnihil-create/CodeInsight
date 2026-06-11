#include<bits/stdc++.h>

using namespace std;
#define rep(i,n) for (int i=0;i<n;i++)
using ll=long long;
using p_i_i=pair<int,int>;

int n;
vector<vector<p_i_i>>v;
bool judge(int bit,int n){
  rep(i,n){
    if(!(bit&(1<<i)))continue;
    for(p_i_i xy:v[i]){
      int x=xy.first;//xが
      int y=xy.second;//正直か不親切かy=1正直y=0不親切
      //y=1なのに「不親切」
      if((y==1)&&!(bit&(1<<x)))return false;
      if((y==0)&&(bit&(1<<x)))return false;
    }
  }return true;
}
int main(){
 cin>>n;
 v.resize(n);
 rep(i,n){
   int a;cin>>a;
   v[i].resize(a);
   for(int j=0;j<a;j++){
     cin>>v[i][j].first>>v[i][j].second;
     --v[i][j].first;
   }
 }

 int res=0;
 for(int bit=0;bit<(1<<n);bit++){

   if(judge(bit,n)){

     int count=0;
     for(int i=0;i<n;i++){
       if(bit&(1<<i))count++;
     }
     res=max(res,count);
   }
 }
 cout<<res<<endl;
return 0;
}