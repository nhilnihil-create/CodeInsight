#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  ll N;
  cin>>N;
  ll a=0;
  vector<char>vec(N);
  for(ll i=0;i<N;i++){
    cin>>vec.at(i);
  }
  for(ll i=0;i<N-2;i++){
    if(vec.at(i)=='A'&&vec.at(i+1)=='B'&&vec.at(i+2)=='C'){
      a+=1;
    }
  }
  cout<<a<<endl;
  
}
