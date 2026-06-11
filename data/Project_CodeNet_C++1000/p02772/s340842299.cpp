#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  ll N;
  cin>>N;
  vector<long long>vec(N);
  for(ll i=0;i<N;i++){
    cin>>vec.at(i);
    if(vec.at(i)%2==0){
      
    if(vec.at(i)%3!=0&&vec.at(i)%5!=0){
      cout<<"DENIED"<<endl;
      return 0;
    }
    }
  }
  cout<<"APPROVED"<<endl;
  

} 