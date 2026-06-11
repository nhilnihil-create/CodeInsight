#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int mod=1000000007;
const int INF=1001001001;


int main() {
  int64_t N;
  cin>>N;
  vector<int64_t>a(N);
  map<int64_t,int>k;
  for(int i=0;i<N;i++){
    cin>>a[i];
    k[a[i]]++;
  }
  if(k.size()>3){cout<<"No"<<endl;}
  else if(k.size()==1){
    if(k[0]==N){cout<<"Yes"<<endl;}
    else{cout<<"No"<<endl;}
  }
  else {
    for(auto c:k){
      if(c.second!=N/3&&c.second!=2*N/3){cout<<"No"<<endl;return 0;}
    }
    if(k.size()==2){
      int64_t two=0,one=0;
      for(auto c:k){
        if(c.second==N*2/3){two=c.first;}
        else {one=c.first;}
      }
      if(two^two^one==0){cout<<"Yes"<<endl;}
      else{cout<<"No"<<endl;}
    }
    else{
      int64_t fac=0;
      for(auto c:k){
        fac^=c.first;
      }
      if(fac==0){cout<<"Yes"<<endl;}
      else{cout<<"No"<<endl;}
    }
  }
  return 0;  
}