#include<bits/stdc++.h>
#define rep(i,n) for (int i =0; i <(n); i++)
using namespace std;
using ll = long long;


int main(){
  int N;
  cin >> N;
  
  vector<pair<int,int>>D(N);
  
  rep(i,N){
    cin >> D[i].first >> D[i].second;
  }
  
  int count = 0;
  
  rep(i,N){
    
    if(count >= 1){
      if(D[i].first == D[i].second){
        count++;
        if(count == 3){
          cout << "Yes" << endl;
          return 0;
        }
        continue;
      }
      else count = 0;
    }
    
    
    if(D[i].first == D[i].second){
      count++;
    }
    
  }
  cout << "No" << endl;
  return 0;
}