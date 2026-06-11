#include<bits/stdc++.h>
using namespace std ; 


int main () {
  int N ; 
  cin >> N ;
  vector<double> v(N) ; 
  double final_ans = 0 ;

  for(int i = 0 ; i <N ; i++){
    cin >> v.at(i) ; 
  }
  sort(v.begin(), v.end()) ;
  final_ans = v.at(0) ;
  
  for(int i = 1 ; i < N ; i++){
    final_ans = (final_ans + v.at(i))/2.0 ; 
  }
  
  
  cout << final_ans << endl ; 
}