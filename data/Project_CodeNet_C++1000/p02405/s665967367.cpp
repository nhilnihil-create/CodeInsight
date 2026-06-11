#include<iostream>
using namespace std;
int main(){
int H,W,i,j,w=0;
	while(cin>>H){	
		cin>>W;
		w=0;
		j=0;
		if(H==0&&W==0){
			break;
		}
		for(j=0;j<H;j++){
			if(w+1<=H){
				for(i=0;i<W;i++){
					cout<<'#';
					if(i+1<W){
						cout<<'.';
						i++;
					}
				}
			}	
				w++;
				cout<<endl;
			if(w+1<=H){
				for(i=0;i<W;i++){
					cout<<'.';
					if(i+1<W){
						cout<<'#';
						i++;
					}		
				}
			
				w++;				
				j++;
				cout<<endl;		
		}	

		}
	cout<<endl;
	}	
return 0;
}