#include <iostream>
using namespace std;

int main()
{
  int h,w;
 
  for( ; ; ){
    cin >> h >> w;
    if(h==0 || w==0) break;
    
    for(int i=0;i<h;i++){
      
      if(i==0 && i==h-1){
	cout << "#";
      }
      for(int j=0;j<w;j++){
	if(j==0 || j==w-1){
	  cout << "#";
	}else if(i==0 || i==h-1){
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