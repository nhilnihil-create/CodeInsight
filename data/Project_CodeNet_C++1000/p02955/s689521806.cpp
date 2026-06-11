#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,K; cin >> N >> K;
  int A[510];
  int sum=0;
  for(int i=0; i<N; i++){
    cin >> A[i];
    sum+=A[i];
  }
  
  vector<int> div;
  int d=1;
  while(d<=sqrt(sum)){
    if(sum%d==0){
      div.push_back(d);
      div.push_back(sum/d);
    }
    d++;
  }
  sort(div.begin(),div.end(),greater<int>());
  
  for(int i=0; i<div.size(); i++){
    int p=div[i];
    
    vector<int> r(N);
    int rsum=0;
    for(int j=0; j<N; j++){
      r[j]=A[j]%p;
      rsum+=r[j];
    }
    sort(r.begin(),r.end());
    rsum/=p;
    int ksum=0;
    for(int j=0; j<N-rsum; j++){
      ksum+=r[j];
    }
    if(ksum<=K){
      cout << p << endl;
      return 0;
    }
  }
} 