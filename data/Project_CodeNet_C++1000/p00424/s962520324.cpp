#include <iostream>
#include <map>

using namespace std;

int main(void){

  int n;
  char c1,c2;
  map <char,char> m;

  while( cin >> n , n ){

    m.clear();    

    for( int i = 0 ; i < n ; i++ ){
      cin >> c1 >> c2;
      m[c1] = c2;
    }

    cin >> n;
    
    while(n--){
      cin >> c1;
      if( m[c1] ) cout << m[c1];
      else cout << c1;
    }
    cout << endl;
    
  }
  
  
  return 0;
}