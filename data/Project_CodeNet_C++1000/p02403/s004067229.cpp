#include<iostream>
using namespace std;
int main(){
  int h, w ;
  cin >> h >> w ;
  while( h != 0 ) {
    int i, n ;
    for( i=0 ; i<h ; i++ ) {
      for( n=0 ; n<w ; n++ ) {
    cout << "#" ;
      }
      cout << endl ;
    }
    cout << endl;
    cin >> h >> w ;
  }
  return 0 ;
}
