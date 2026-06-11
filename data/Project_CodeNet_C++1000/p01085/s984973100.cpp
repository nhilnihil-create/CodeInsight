#include <iostream>
using namespace std;

int main(){
	while(1){
		int m,nmin,nmax;
		
		cin>> m>>nmin>>nmax;
		
		if(m==0 && nmin==0 && nmax == 0)
			break;
			
		int P[m];
		for(int i=0; i<m ;i++){
			cin>>P[i];
		}
		
		int maxgap=0;
		int chosen=0;
		for(int i=nmin-1; i<nmax; i++){
			
			if(maxgap <= (P[i]-P[i+1])){
				maxgap=P[i]-P[i+1];
				chosen=i+1;
			}
		}
		cout<<chosen<<endl;
	}
	return 0;
}