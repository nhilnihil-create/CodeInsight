#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int k , n;
  cin >> k >> n ;
  int a[n] ;
  for ( int i=0 ; i< n ; i++){
    cin >> a[i] ;
  }
  vector<int> dis(n) ;
  for ( int i=0 ; i<n-1 ; i++){
    dis.at(i)=a[i+1]-a[i] ;
  }
  dis.at(n-1)=k-a[n-1]+a[0];
  sort(dis.begin() , dis.end() ) ;
  cout << k-dis.at(n-1) << endl ;
}