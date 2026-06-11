#include <iostream>
using namespace std;

int main(){
  int H, W;
  while(cin >> H >> W){
    if(H==0 && W==0){
      return 0;
    }
    else{
      for(int i=0; i<W; i++){
	cout << "#";
      }
      cout << endl;
      for(int j=0; j<(H-2); j++){
	cout << "#";
	for(int k=0; k<(W-2); k++){
	  cout << ".";
	}
	cout << "#" << endl;
      }
      for(int l=0; l<W; l++){
	cout << "#";
      }
      cout << endl << endl;
    }
  }
}