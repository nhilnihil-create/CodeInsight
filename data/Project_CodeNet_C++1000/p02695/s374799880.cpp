             
#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()

ll N,M,Q;
ll ma;
vector<vector<ll>> vec;
vector<ll> x;

void  judge(ll index ,ll value) {
   if(index==N) {
ll point=0;
    for(ll i=0;i<Q;i++) {
      if(x[vec[i][1]-1]-x[vec[i][0]-1]==vec[i][2]) {
point+=vec[i][3];
      }
    }
 ma=max(ma,point);
    return;
  }
  ll i=0;
 
  while(i+value<=M) {
    x[index]=i+value;
   
    judge(index+1,i+value);
  i++;
}
return;
}
  

 
int main() {
  cin>>N>>M>>Q;
ma=0;
  x=vector<ll>(N,0);
  vec=vector<vector<ll>>(Q,vector<ll>(4));
for(ll i=0;i<Q;i++) {
for(ll j=0;j<4;j++) {
cin>>vec[i][j];
}
}
  judge(0,1);
  cout<<ma<<endl;
  

}

              
              
              
              
              
              
              
