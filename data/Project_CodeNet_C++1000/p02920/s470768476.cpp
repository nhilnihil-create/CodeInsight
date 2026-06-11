#include<bits/stdc++.h>
using namespace std;
#define int long long 

signed main(void){
  
  int N; cin >> N;
  int SIZE = 1 << N;
  multiset<int> target; //これだけ作らなければならない
  
  for(int i = 0; i < SIZE; i++){ 
    int a; cin >> a;
    target.insert(a);
  }
  
  int M = *target.rbegin();
  vector<int> V;
  V.push_back(M);
  
  for(int i = 0; i < N; i++){ 
   
    int m = V.size();
    
    vector<int> stock;
    
    for(int j = 0; j < m; j++){
        // V[j]の子を作れないかどうか考える
      int p = V[j]; 
      auto itr = target.lower_bound(p);
      if( itr == target.begin() ){ cout << "No" <<  endl; return 0;}
      
      itr--;
      
      stock.push_back(*itr);
      
      target.erase(itr);
    }
    
    for(int j = 0; j < stock.size(); j++){
      V.push_back(stock[j]);
    }
    
   sort(V.rbegin(),V.rend());
    
    
  }
  
  //SIZE回無事に終わったらYes
  
  cout << "Yes" << endl;
  
  return 0;
}