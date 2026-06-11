#include <bits/stdc++.h>
using namespace std;

int main(){
  double N , b , sum , ans ;
  cin >> N ;
  for(int i=0;i<N;i++){
    cin >> b ;
    sum += 1/b;
  }
  
  cout << (double)(1/sum) << endl;
}