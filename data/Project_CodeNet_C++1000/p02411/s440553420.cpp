#include<iostream>
using namespace std;
main(){
  int m,f,r,d=0,e=0;
  while(1){  
  cin >> m >> f >> r ;
  d=m+f;


  if(m==-1 && f==-1 && r==-1)break;
  else if(m==-1 || f==-1){
    cout <<"F\n";
  }
  else if(d>=80 ){
      cout<<"A\n";
    }
  else if(d>=65 && d<80){
      cout<<"B\n";
    }
  else if(d>=50 && d<65){
      cout<<"C\n";
    }
  else if(d>=30 && d<50){
      if(r>=50){
	cout<< "C\n";
      }

      else cout<< "D\n";
    }
  else if(d<30){
 cout << "F\n";
  }
 d=0;
  }
    
  
}