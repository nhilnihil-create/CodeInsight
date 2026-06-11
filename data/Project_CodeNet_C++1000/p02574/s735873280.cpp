#include <bits/stdc++.h>
using namespace std;

vector<int> hurui(int n){
  vector<int> d(n+1,-1);
  d[1]=1;
  int curr_d;
  for(int i=2;i<=n;i++){
    if(d[i]==-1){
      curr_d=i;
      for(int j=1;j<n/curr_d+1;j++){
        if(d[curr_d*j]==-1){
          d[curr_d*j]=curr_d;
        }
      }
    }
  }
  return d;
}


bool gozyohou1(vector<int> a){
  sort(a.begin(),a.end());
  vector<int> d=hurui(a.at((int)a.size()-1));
  set<int> primes;
  int p;
  int dp;
  for(int i=0;i<(int)a.size();i++){
    p=a.at(i);
    while(d[p]!=p){
      if(primes.count(d[p])){
        return false;
      }
      primes.insert(d[p]);
      dp=d[p];
      while(p%dp==0){
        p/=dp;
      }
    }
    if(primes.count(d[p])){
      return false;
    }
    if(p!=1){
      primes.insert(d[p]);
    }
  }
  return true;
}
bool gozyohou2(vector<int> a){
  sort(a.begin(),a.end());
  while(a.at(0)>1){
    for(int i=1;i<(int)a.size();i++){
      a.at(i)%=a.at(0);
    }
    a.erase(remove_if(a.begin(),a.end(),[](int x){return x==0;}),a.end());
    if((int)a.size()==1){
      return false;
    }
    sort(a.begin(),a.end());
  }
  return true;
}

int main(){
  int n;
  cin>>n;
  vector<int> a(n);
  for(int i=0;i<n;i++){
    cin>>a.at(i);
  }
  if(gozyohou1(a)){
    cout<<"pairwise coprime"<<endl;
    return 0;
  }
  if(gozyohou2(a)){
    cout<<"setwise coprime"<<endl;
    return 0;
  }
  cout<<"not coprime"<<endl;
}
  
  