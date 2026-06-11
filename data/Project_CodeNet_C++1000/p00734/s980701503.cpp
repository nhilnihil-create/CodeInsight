#include<iostream>

using namespace std;

int sum(int* ,int );

int main(void){

  int n,m,sub,flag,cnum1,cnum2,i,j,sum1,sum2;
  cin >> n >> m;
  int a[101],b[101];

  while( (n==0&&m==0) != 1 ){ 

    //
    
    for(i=0;i<n;i++){
      cin >> a[i];
    }
    for(j=0;j<m;j++){
      cin >> b[j];
    }
    sub = sum(a,n) - sum(b,m);


    //

    
    flag=0;
    for(i=0;i<n;i++){
      for(j=0;j<m;j++){
	if( (a[i] - b[j])*2 == sub ){
	  if(flag==0){
	    cnum1 = a[i];
	    cnum2 = b[j];
	    flag++;
	  }else{
	    if(a[i] + b[j] < cnum1 + cnum2){
	      cnum1 = a[i];
	      cnum2 = b[j];
	    }
	  }
	}
      }
    }


    if(flag==0){
      cout << "-1" << endl;
    }else{
      cout << cnum1 << " " <<  cnum2 << endl;
    }



    cin >> n >> m;
  }
  
  return 0;
}

int sum(int* p,int n){
  int s=0,i;
  for(i=0;i<n;i++) s+=p[i];
  return s;
}
  