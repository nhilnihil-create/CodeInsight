#include<iostream>
using namespace std;

int Check(int jwelx[],int jwely[],int x,int y,int n){

  for(int i=0; i<n; i++){
    if(jwelx[i]==x && jwely[i]==y)
      return i;
  }
      
  return -1;
}


int main(){

  int n,m;
  int jwelx[20],jwely[20];
  int x,y,d;
  char angle;
  int sum;
  int tmp;

  while(cin >> n){
    if(n==0){ break; }

    for(int i=0; i<n; i++){
      cin >> jwelx[i] >> jwely[i];
    }

    cin >> m;
    sum=0;
    x=y=10;

    tmp = Check(jwelx,jwely,x,y,n);
    if(tmp!=-1){
      jwelx[tmp]=-1;
      sum++;
    }

    for(int i=0; i<m; i++){
      cin >> angle >> d;


      //  cout << "x:" << x << " y:" << y << endl;


      if(angle=='N'){
	for(int i=0; i<d; i++){
	  y++;

	  tmp = Check(jwelx,jwely,x,y,n);
	  if(tmp!=-1){
	    jwelx[tmp]=-1;
	    sum++;
	  }
	}
      }
      else if(angle=='E'){
	for(int i=0; i<d; i++){
	  x++;
	  
	  tmp = Check(jwelx,jwely,x,y,n);
	  if(tmp!=-1){
	    jwelx[tmp]=-1;
	    sum++;
	  }	  
	}
      }
      else if(angle=='S'){
	for(int i=0; i<d; i++){
	  y--;
	  
	  tmp = Check(jwelx,jwely,x,y,n);
	  if(tmp!=-1){
	    jwelx[tmp]=-1;
	    sum++;
	  }	  
	}
      }
      else{
	for(int i=0; i<d; i++){
	  x--;

	  tmp = Check(jwelx,jwely,x,y,n);
	  if(tmp!=-1){
	    jwelx[tmp]=-1;
	    sum++;
	  }
	}
      }

    }
    //for

    if(sum==n)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;

  }


  return 0;
}