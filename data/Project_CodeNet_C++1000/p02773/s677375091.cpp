#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  ll N;
  cin>>N;
  vector<string>vec(N);
  for(ll i=0;i<N;i++){
    cin>>vec.at(i);
  }
  sort(vec.begin(),vec.end());
  ll a=0;
  vector<ll>veco(1);
  vector<string>ve(1);
  ve.at(0)=vec.at(0);
  for(ll i=1;i<N;i++){
    if(vec.at(i-1)==vec.at(i)){
      veco.at(veco.size()-1)+=1;
      a=max(veco.at(veco.size()-1),a);
    }
    else{
      veco.push_back(0);
      ve.push_back(vec.at(i));
    }
  }
  vector<string>result(0);
  for(ll i=0;i<veco.size();i++){
    if(veco.at(i)==a){
      result.push_back(ve.at(i));
    }
  }
  sort(result.begin(),result.end());
  for(ll i=0;i<result.size();i++){
    cout<<result.at(i)<<endl;
  }
}