#include <iostream>
using namespace std;

int main()
{
  int h,w;
  int i,j;
    
  for( ; ; ){
    cin >> h >> w;
    if(h==0 || w==0) break;
    for(i=0;i<h;i++){
      if(i%2==0){
	for(j=0;j<w;j++){
	  if(j%2==0){
	    cout << "#";
	  }else{
	    cout << ".";
	  }
	}
	cout << endl;
      }else{
	for(j=0;j<w;j++){
	  if(j%2!=0){
	    cout << "#";
	  }else{
	    cout << ".";
	  }
	 }
	cout << endl;
      }
    }
    cout << endl;  
  }   
  return 0;
}