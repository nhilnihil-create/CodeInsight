#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  vector<vector<ll>>vec(3,vector<ll>(3));
  vector<vector<ll>>ans(3,vector<ll>(3,0));
  for(ll i=0;i<3;i++){
    for(ll j=0;j<3;j++){
      cin>>vec.at(i).at(j);
    }
  }
  ll N;
  cin>>N;
  vector<ll>bin(N);
  for(ll i=0;i<N;i++){
    cin>>bin.at(i);
  }
  for(ll k=0;k<N;k++){
    for(ll i=0;i<3;i++){
      for(ll j=0;j<3;j++){
        if(bin.at(k)==vec.at(i).at(j)){
          ans.at(i).at(j)=1;
          break;
        }
      }
    }
  }
  if(ans.at(0).at(0)==1&&ans.at(1).at(1)==1&&ans.at(2).at(2)==1){
    cout<<"Yes"<<endl;
    return 0;
  }
  if(ans.at(0).at(2)==1&&ans.at(1).at(1)==1&&ans.at(2).at(0)==1){
    cout<<"Yes"<<endl;
    return 0;
  }
  for(ll i=0;i<3;i++){
    if(ans.at(i).at(0)==1&&ans.at(i).at(1)==1&&ans.at(i).at(2)==1){
      cout<<"Yes"<<endl;
      return 0;
    }
    if(ans.at(0).at(i)==1&&ans.at(1).at(i)==1&&ans.at(2).at(i)==1){
      cout<<"Yes"<<endl;
      return 0;
    }
  }
  cout<<"No"<<endl;
}
    
