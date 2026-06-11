#include<iostream>
#include<algorithm>
using namespace std;

int main(void){
  int H, W;

  cin >> H >> W;
  do{
    for( int i = 0; i < H; i++ ){
      if ( i == 0 || i == H-1 ){
	for( int j = 0; j < W; j++ ){
	  cout << '#';
	}
      }else{
	for( int j = 0; j < W; j++ ){
	  if( j == 0 || j == W-1 ){
	    cout << '#';
	  }else{
	    cout << '.';
	  }
	}
      }
      cout << endl;
    }
    cout << endl;
    
    cin >> H >> W;
  }while( H != 0 || W != 0);
  
  return 0;
}