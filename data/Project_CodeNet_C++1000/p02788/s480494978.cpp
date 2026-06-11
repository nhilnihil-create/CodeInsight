#include <bits/stdc++.h>
using namespace std;


int main(){
  int64_t N,D,A,ans=0;
  cin >> N >> D >> A;
  vector<pair<int64_t,int64_t>> X(N);
  queue<pair<int64_t,int64_t>> P;
  for(int64_t i=0;i<N;i++){
    cin >> X.at(i).first >> X.at(i).second;
  }
  sort(X.begin(),X.end());
  int64_t a=0;
  for(int64_t i=0;i<N;i++){
    while(!P.empty()){
      if(P.front().first<X.at(i).first){
        a-=P.front().second;
        P.pop();
      }else{
        break;
      }
    }
    if(X.at(i).second<=a){
      X.at(i).second=0;
      continue;
    }else{
      X.at(i).second-=a;
    }
    ans+=(X.at(i).second-1)/A+1;
    a+=A*((X.at(i).second-1)/A+1);
    P.push(pair<int64_t,int64_t>(X.at(i).first+2*D,A*((X.at(i).second-1)/A+1)));
    
  
      
  }
  cout << ans << endl;
}
