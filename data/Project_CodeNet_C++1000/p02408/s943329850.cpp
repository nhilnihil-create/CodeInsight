
#include<iostream>
using namespace std;

int main(){
	int n,i,j;
	int cards[4][13]={0};
	char suit; //?????????
	int num;;
	
	cin>>n;
	
	for(i=0;i<n;i++){
		cin>>suit>>num;
		
		if(suit=='S'){
			cards[0][num-1]++;
		}else if(suit=='H'){
			cards[1][num-1]++;
		}else if(suit=='C'){
			cards[2][num-1]++;
		}else{
			cards[3][num-1]++;
		}
	}
	for(i=0;i<4;i++){
		for(j=0;j<13;j++){
			if(cards[i][j]==0){
				if(i==0){
					cout<<'S'<<" "<<j+1<<endl;
				}else if(i==1){
					cout<<'H'<<" "<<j+1<<endl;
				}else if(i==2){
					cout<<'C'<<" "<<j+1<<endl;
				}else{
					cout<<'D'<<" "<<j+1<<endl;
				}
			}
		}
	}
	
	return 0;
}