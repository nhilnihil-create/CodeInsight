#include<bits/stdc++.h>
using namespace std ; 


int main() {
  int N ; 
  cin >> N ; 
  
  unordered_map<string , int> M ; 
  
  for(int i = 0 ; i < N ; i++){
    string S ; 
    cin >> S ; 
    sort(S.begin(),S.end()) ; 
    M[S]++ ;   
  }
  int64_t T = 0 ; 
    
for (auto p : M) {
  auto v = p.second;
    for( int i = 0 ; i < v ;i++){
      T += i ; 
    }
   
  
}

  cout << T << endl ; 
}