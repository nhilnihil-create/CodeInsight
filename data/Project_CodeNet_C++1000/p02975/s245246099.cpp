#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int mod=1000000007;
const int INF=1001001001;

vector<pair<int64_t,int64_t>>prime_factorize(int64_t x){
  vector<pair<int64_t,int64_t>>p;
  for(int64_t i=2;i*i<=x;i++){
    int cnt=0;
    if(x%i==0){
    while(x%i==0){cnt++;x/=i;}
    p.push_back(make_pair(i,cnt));
    }
  }
  if(x!=1){p.push_back(make_pair(x,1));}
  return p; 
}

int main() {
  int N;
  cin>>N;
  vector<int>a(N);
  for(int i=0;i<N;i++){
    cin>>a[i];
  }
  map<int,int>k;
  for(int i=0;i<N;i++){
    k[a[i]]++;
  }
  if(k[0]==N){cout<<"Yes"<<endl;}
  else if(N%3!=0){
    if(k[0]==N){cout<<"Yes"<<endl;}
    else {cout<<"No"<<endl;}
  }
  else{
    int q=0;
    bool ok=true;
    int test=N/3;
    for(auto c:k){
      if(c.second%test!=0){ok=false;}
      q^=c.first;
      for(int i=0;i<=c.second/test;i++){q^=c.first;}
    }
    if(q!=0){ok=false;}
    if(ok){cout<<"Yes"<<endl;}
    else{cout<<"No"<<endl;}
  }
  return 0;  
}