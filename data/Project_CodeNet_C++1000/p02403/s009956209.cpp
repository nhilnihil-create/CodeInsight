#include<iostream>
using namespace std;

 int main(){
	 int x,y,i,j;
	 while(1){
		 cin >> x >>y;
		 if(x==0&&y==0){
			 break;
		 }
		 for(i=0;i<x;i++){
			 for(j=0;j<y;j++){
				 cout<<"#";
			 }
			 cout << endl;
		 }
		 cout<<endl;
	 }
	 return 0;


 }




