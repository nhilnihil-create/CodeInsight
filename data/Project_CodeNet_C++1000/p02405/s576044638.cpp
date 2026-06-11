#include<stdio.h>
#include<iostream>
using namespace std;

int main(){
	int H,W,M;
	
	while(1){
		cin >> H >> W ;
		if(W==0&&H==0)return 0;
		if(W%2==0&&H%2==0){
			for(int i=0;i<H/2;i++){
				for(int i=0;i<W/2;i++){
					cout << "#." ;
				}
				cout << endl;
				for(int i=0;i<W/2;i++){
					cout << ".#" ;
				}
				cout << endl;
			}
			cout << endl;
			
		}else if(W%2==0&&H%2==1){
			for(int i=0;i<H/2;i++){
				for(int i=0;i<W/2;i++){
					cout << "#." ;
				}
				cout << endl;
				for(int i=0;i<W/2;i++){
					cout << ".#" ;
				}
				cout << endl;
			}
			for(int i=0;i<W/2;i++){
					cout << "#." ;
				}
			cout << endl << endl;
		
		}else if(W%2==1&&H%2==0){
			for(int i=0;i<H/2;i++){
				for(int i=0;i<W/2;i++){
					cout << "#." ;
				}
				cout << "#" << endl;
				for(int i=0;i<W/2;i++){
					cout << ".#" ;
				}
				cout << "." << endl;
			}
			cout << endl;
			
		}else if(W%2==1&&H%2==1){
			for(int i=0;i<H/2;i++){
				for(int i=0;i<W/2;i++){
					cout << "#." ;
				}
				cout << "#" << endl;
				for(int i=0;i<W/2;i++){
					cout << ".#" ;
				}
				cout << "." << endl;
			}
			for(int i=0;i<W/2;i++){
					cout << "#." ;
			}
			cout << "#" << endl << endl;
			
		}
	
	}
	return 0;
}