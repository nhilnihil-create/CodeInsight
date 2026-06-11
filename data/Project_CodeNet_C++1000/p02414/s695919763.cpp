# include <iostream>
# include <stdint.h>
# include <stdio.h>
# include <math.h>
using namespace std;


int main(){
	long long n,m,l;
	cin>>n>>m>>l;
	long long A[n][m] ={{0}};
	long long B[m][l] ={{0}};
	long long C[n][l] ={};
	for(int a=0;a<n;a++){
		for(int b=0;b<m;b++){
			cin >>A[a][b];
		}
	}
	for(int i=0;i<m;i++){
		for(int j =0;j<l;j++){
			cin >>B[i][j];
		}
	}
	
	for(int a=0;a<n;a++){
		for(int b=0;b<l;b++){
			for(int c=0;c<m;c++){
				C[a][b] += A[a][c] * B[c][b];
			}
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<l;j++){
			if(j==0){
				cout<<C[i][j];
			}
			else{
				cout<<" "<<C[i][j];
			}

			
		}
		cout<<"\n";
	}
	return 0;
}

