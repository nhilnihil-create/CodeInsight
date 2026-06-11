#include <iostream>
using namespace std;
int main(){
  int n=1000 ,m ,coin=0;
  while( true ){
    cin >> m;

    if( m == 0 ){
      break;
    }
    n -= m;
    if( n >= 500 ){
      coin += n / 500;
      n %= 500;
    }
    
    if( n >= 100 ){
      coin += n / 100;
      n %= 100;
    } 
    
    if( n >= 50 ){
      coin += n / 50;
      n %= 50;
    } 
    
    if( n >= 10 ){
      coin += n / 10;
      n %= 10;
    } 
    
    if( n >= 5 ){
    coin += n / 5;
    n %= 5;
    }
    
    if( n >= 1 ){
      coin += n;
    }
  
    cout << coin << endl;
    n = 1000;
    coin = 0;
  }
}