#include<iostream>
using namespace std;

int main(void){

  int height,width,i,j;
  
  while(cin >> height >> width){

    if(height == 0 && width == 0) break;
    
    for(j=0; j<height; j++){
      for(i=0; i<width; i++){
	cout << "#";
	if(i == width - 1) cout << endl;
      }
    }
    cout << endl;
  }
  return 0;
}