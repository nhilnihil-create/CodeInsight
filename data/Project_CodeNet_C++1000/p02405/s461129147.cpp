#include<iostream>
using namespace std;

int main(void){
  int H, W, count=0;

  cin >> H >> W;
  do{
    for( int i = 0; i < H; i++ ){
      for( int j = 0; j < W; j++ ){
	if( count % 2 == 0) {
	  cout << '#';
	  count++;
	}else{
	  cout << '.';
	  count++;
	}
      }
      if ( W % 2 == 0){
	count++;
      }
      cout << endl;
    }
    cout << endl;
      
    count = 0;
      
    cin >> H >> W;
  }while( H != 0 || W != 0);
  
  return 0;
}