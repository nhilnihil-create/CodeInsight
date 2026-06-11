#include<iostream>
using namespace std;

int main(){
	int H,W,i,j,a,b;
	char x[H][W];
	
	while(1){
		cin>>H>>W;
		
		if(H==0 && W==0)
			break;

		for(i=0;i<H;i++){
			for(j=0;j<W;j++){
				/*if(i==0 && j==0){
					cout<<'#';
					x[i][j]='#';
				}
				if(x[i][j-1]=='#'){
					cout<<".";
					x[i][j]='.';
				}
				else if(x[i][j-1]=='.'){
					cout<<"#";
					x[i][j]='#';
				}
				else if(i>0 && x[i-1][0]=='#'){
					cout<<".";
					x[i][j]='.';
				}
				else if(i>0 && x[i-1][0]=='.'){
					cout<<"#";
					x[i][j]='#';
				}*/
				 if( (i+j) % 2 == 0)
				 	cout << "#";
                		 else
                		 	cout << ".";
			}
			cout<<endl;
		}
		cout<<endl;
	}
}
				
					
	