#include <iostream>
using namespace std;

int main(){
  int H, W;
  while(cin>> H >> W){
    if(H==0 && W==0)break;
    else{
      for(int i=0; i<H; i++){
	if(i%2==1){
	  for(int j=0; j<W; j++){
	    if(j%2==1)
	      cout << "#";
	    else
	      cout << ".";
	  }
	  cout << endl;
	}
	else{
	  for(int j=0; j<W; j++){
	    if(j%2==1)
	      cout << ".";
	    else
	      cout << "#";
	  }
	  cout << endl;
	}
	
      }
      cout << endl;
    }
  }
  return 0;
}