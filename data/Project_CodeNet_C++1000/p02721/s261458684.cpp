#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef long int li;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
typedef pair<ll, ll>P;
typedef tuple<ll, int, int>T;
#define PI 3.14159265358979


int main(){
  ll N,K,C;
  cin>>N>>K>>C;
  string S;
  cin>>S;
  vector<P>A(N+2);
  vector<P>B(N+2);
  rep(i,N+2){A[i]=P(0,0);B[i]=P(0,0);}
  A[0]=P(0,-300000);
  B[N+1]=P(0,500000);
  //前から最適に働く
  for(ll i=0;i<N;i++){
    if(S[i]=='x'){
      A[i+1]=A[i];
    }
    else{
      ll k=i+1;
      //働ける場合
      if(k-A[i].second>C){
      auto t=A[i];  
      t.first+=1;
      t.second=k; 
       
      A[i+1]=P(t.first,t.second);
      }
      if(k-A[i].second<=C){A[i+1]=A[i];}
    }
    
  }
  //後ろから最適に働く
  for(ll i=N-1;i>=0;i--){
    if(S[i]=='x'){
      B[i+1]=B[i+2];continue;
    }
    auto t=B[i+2];
    ll k=i+1;
    //働ける場合
    if(t.second-k>C){
      t.first++;
      t.second=k;
      B[i+1]=t;
    }
    else{B[i+1]=B[i+2];}
  }
  rep(i,N){
    if(S[i]=='x'){continue;}
    auto p=B[i+2];
    auto q=A[i];
    ll sum=p.first+q.first;
    if(p.second-q.second<=C){sum--;}
    if(sum<K){cout<<i+1<<endl;}
  }  
}
