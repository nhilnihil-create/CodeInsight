#include<bits/stdc++.h>
using namespace std ; 

int main() {
  int N ; 
  cin >> N ; 
  vector<int> X(N) ;
  vector<int> Y(N) ;
  int T=0 ; 
  pair<int,int> Z[110] ; 
  
  for(int i = 0 ; i < N ; i++){
    cin >> X.at(i) ; 
  }
  
  for(int j = 1 ; j < 100 ; j++){
    for(int i = 0 ; i < N ; i++){
      Y.at(i) = (X.at(i) - j )*(X.at(i) - j ) ; 
      T = T + Y.at(i) ;
    }
    
    Z[j] = make_pair(T , j) ; 
    sort(Z , Z+j) ; 
    T = 0 ; 
    //cout << Z[1].first << endl ; 
  }
  
	cout << Z[1].first << endl ;
}