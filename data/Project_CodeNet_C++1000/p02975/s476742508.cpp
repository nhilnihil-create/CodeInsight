#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  ll N,a,zero=0; cin>>N;
  vector<vector<ll>>keep(3,vector<ll>(2,-1));
  bool finish=false;
  for(int i=0; i<N; i++){
    cin>>a;
    if(a==0){
      zero++;
      continue;
    }
    for(int j=0; j<3; j++){
      if(keep[j][0]==-1){
        keep[j][0]=a;
        keep[j][1]=1;
        break;
      }
      if(keep[j][0]==a){
        keep[j][1]++;
        break;
      }
      if(j==2) finish=true;
    }
    if(finish){
      cout<<"No"<<endl;
      return 0;
    }
  }
  
  if(zero==N){
    cout<<"Yes"<<endl;
    return 0;
  }
  if(N%3==0){
    ll z=N/3;
    if(zero==z && keep[0][1]==2*z){
      cout<<"Yes"<<endl;
      return 0;
    }
    if(zero==0){
      if(keep[0][1]==z && keep[1][1]==z && keep[2][1]==z){
        if(((keep[0][0]^keep[1][0])^keep[2][0])==0){
          cout<<"Yes"<<endl;
          return 0;
        }
      }
    }
  }     
  cout<<"No"<<endl;
}