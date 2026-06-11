#include <iostream>

using namespace std;

int main()
{
  int h, w;
  int a, b;
  while(1){
    cin >> h >> w;
    if(h==0 && w==0) break;
    for(a=0; a<h; a++){
      for(b=0; b<w; b++){
	if(a==0|a==h-1|b==0|b==w-1){
	  cout << "#";
	}else{
	  cout << ".";
	}
      }
      cout << endl;
    }
    cout << endl;
  }
  return 0;
}