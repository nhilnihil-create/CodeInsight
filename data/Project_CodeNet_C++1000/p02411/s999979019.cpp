#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int main(){
	int chukan,kimatsu,saishi;
	while(cin>>chukan>>kimatsu>>saishi){
		if(chukan==-1&&kimatsu==-1&&saishi==-1) break;
			if(chukan==-1||kimatsu==-1||chukan+kimatsu<30){
				cout<<"F"<<endl;
			}if(chukan==-1||kimatsu==-1){
				chukan+=1;
			}else if(chukan+kimatsu>=80){
				cout<<"A"<<endl;
			}else if(chukan+kimatsu>=65){
				cout<<"B"<<endl;
			}else if(chukan+kimatsu>=50){
				cout<<"C"<<endl;
			}else if(chukan+kimatsu>=30){
				if(saishi>=50){
					cout<<"C"<<endl;
				}else{
					cout<<"D"<<endl;
				}
			}
	}
	return 0;
}