#include <bits/stdc++.h>
using namespace std;

int main() {
  int n ;
  cin >> n;
  vector <int> v(n) ;
  vector <double> a(n) ;
  a.at(0)  = 0.5;
   cin >> v.at(0) ;
  for (int i=1 ; i<n-1 ; i++){
    cin >> v.at(i) ;
    a.at(i) = a.at(i-1)*0.5 ;
  }
  cin >> v.at(n-1) ;
  a.at(n-1)=a.at(n-2) ;
  sort( v.begin() , v.end() );
  sort ( a.begin() , a.end() );
  double V = 0 ;
  for (int i=0 ; i<n ; i++){
    V += a.at(i)*v.at(i) ;
  }
  cout << V << endl;
}