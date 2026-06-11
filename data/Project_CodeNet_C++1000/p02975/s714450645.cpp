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

  vector<int>p;//要素の種類を格納する配列
  int q=0;
  for(auto c:k){
    p.push_back(c.first);
    q^=c.first;
  }
  int s=k.size();
  if(k[0]==N){cout<<"Yes"<<endl;}
  else if(N%3!=0){
    if(k[0]==N){cout<<"Yes"<<endl;}
     else{cout<<"No"<<endl;}
  }
  else { 
    bool ok=false;
    if(s==3&&k[p[0]]==N/3&&k[p[1]]==N/3&&k[p[2]]==N/3){ok=true;}
    else if(k.size()==2){
      if(k[p[0]]==2*N/3){ok=true;q^=p[0];}
      if(k[p[1]]==2*N/3){ok=true;q^=p[1];}
    }
    if(q!=0){ok=false;}
    if(ok){cout<<"Yes"<<endl;}
    else{cout<<"No"<<endl;}
  }
  return 0;  
}