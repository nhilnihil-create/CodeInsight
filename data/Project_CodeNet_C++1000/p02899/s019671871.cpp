#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n;
  cin >> n;
  vector <pair <int , int>> a(n);
  for (int i=0 ; i<n ; i++){
    int b ;
    cin >> b;
    a.at(i) = make_pair(b,i+1) ;
  }
  sort ( a.begin() , a.end() ) ;
  for ( int i = 0 ; i< n ; i++){
    int c,b;
     tie(c,b)=a.at(i) ;
    cout << b << ' ';
  }
  cout << endl;
}