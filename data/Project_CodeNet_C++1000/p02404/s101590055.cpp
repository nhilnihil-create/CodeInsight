#include <iostream>
using namespace std;

int main(){
  int h,w;
  
  while(1){
    cin >> h >> w;
    if(h==0 && w==0) break;
    
    for(int i=0;i<h;i++){
      if(i==0) {
	for(int j=0;j<w;j++)
	  if(j==w-1) cout << "#" << endl;
	  else cout << "#";
      }
      else if(i==h-1){
	for(int j=0;j<w;j++)
	if(j==w-1) cout << "#" << endl;  
	else cout << "#";
      }
      else{
	for(int j=0;j<w;j++){
	  if(j==0) cout << "#";
	  else if(j==w-1) cout << "#" << endl;
	  else cout << ".";
	}
      }
    }
    cout << endl;
  }
  return 0;
}