#include <bits/stdc++.h>
using namespace std;
 


int main() {
 int n;
 cin>>n;
 
  
  if(n % 2==0){
  cout <<"0.500000000000"<<endl;
  }
  if(n % 2!=0){
  double i=(n+1)/2;
    cout << fixed << setprecision(10);
    cout << i / n <<endl;
  
  }

}