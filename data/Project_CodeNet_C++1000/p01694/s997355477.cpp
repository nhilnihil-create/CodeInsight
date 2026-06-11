#include <iostream>
#include <string>
using namespace std;
int main(){
  int i,n,a;
  string asi[100];
  while(1){
    cin>>n;
    if(n==0) break;
    else {
      for(i=0;i<n;i++){
	cin>>asi[i];
      }
      a=0;
      for(i=0;i<n-1;i++){

	  if(asi[i]=="lu"){
	    if(asi[i+1]=="ru"){
	      a++;
	    
	    }
	  }
	  if(asi[i]=="ru"){
	    if(asi[i+1]=="lu"){
	      a++;
	     
	    }
	  }
	
	
	  if(asi[i]=="ld"){
	    if(asi[i+1]=="rd"){
	      a++;
	    }
	  }
	  if(asi[i]=="rd"){
	    if(asi[i+1]=="ld"){
	      a++;
	    }
	  }
	
      }
      cout<<a<<endl;
    }
  }

  return 0;
}