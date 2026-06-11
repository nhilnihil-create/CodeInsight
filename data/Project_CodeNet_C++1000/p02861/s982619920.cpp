#include<bits/stdc++.h>
using namespace std ; 

int main() {
  double N ; 
  cin >> N ; 
  vector<double> x(N) , y(N) ;
  vector<int> P(N) ; 
  double T=0;
  double C= 0  ; 
  
  
  
  for(int i = 0 ; i < N ; i++){
    P.at(i) = i ; 
    cin >> x.at(i) ; 
    cin >> y.at(i) ; 
  }
  
  do{ 
    for(int i = 0 ;  i < N-1 ; i++){
      T += sqrt( pow(x.at(P.at(i+1))-x.at(P.at(i)),2) + pow(y.at(P.at(i+1))-y.at(P.at(i)),2) ) ;
    }
    C++ ; 
    
  } while (next_permutation(P.begin() , P.end()) ); 
  

  cout << fixed << setprecision(10) << T/C << endl ;
 
  
}