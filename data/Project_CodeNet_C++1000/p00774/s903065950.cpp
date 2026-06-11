#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main(){
	int stone[10][5];
	int h;
	while(scanf("%d",&h) && h!=0){
		int score=0;
		for(int i=0;i<h;i++){
			for(int j=0;j<5;j++){
				scanf("%d",&stone[i][j]);
			}
		}

		int a=1;
		while(a!=0){
			a=0;
			for(int i=0;i<h;i++){
				if((stone[i][0]==stone[i][1]) && (stone[i][1]==stone[i][2]) && (stone[i][2]==stone[i][3]) && (stone[i][3]==stone[i][4])){
					score += stone[i][0]*5;
					for(int j=i;j>0;j--){
						for(int k=0;k<5;k++){
							stone[j][k] = stone[j-1][k];
						}
					}
					for(int j=0;j<5;j++){
						stone[0][j] = 10+j;
					}
					a++;
				}else if((stone[i][0]==stone[i][1]) && (stone[i][1]==stone[i][2]) && (stone[i][2]==stone[i][3])){
					score += stone[i][0]*4;
					for(int j=i;j>0;j--){
						for(int k=0;k<4;k++){
							stone[j][k] = stone[j-1][k];
						}
					}
					for(int j=0;j<4;j++){
						stone[0][j] = 10+j;
					}
					a++;
				}else if((stone[i][1]==stone[i][2]) && (stone[i][2]==stone[i][3]) && (stone[i][3]==stone[i][4])){
					score += stone[i][1]*4;
					for(int j=i;j>0;j--){
						for(int k=1;k<5;k++){
							stone[j][k] = stone[j-1][k];
						}
					}
					for(int j=1;j<5;j++){
						stone[0][j] = 10+j;
					}
					a++;
				}else if((stone[i][0]==stone[i][1]) && (stone[i][1]==stone[i][2])){
					score += stone[i][0]*3;
					for(int j=i;j>0;j--){
						for(int k=0;k<3;k++){
							stone[j][k] = stone[j-1][k];
						}
					}
					for(int j=0;j<3;j++){
						stone[0][j] = 10+j;
					}
					a++;
				}else if((stone[i][1]==stone[i][2]) && (stone[i][2]==stone[i][3])){
					score += stone[i][1]*3;
					for(int j=i;j>0;j--){
						for(int k=1;k<4;k++){
							stone[j][k] = stone[j-1][k];
						}
					}
					for(int j=1;j<4;j++){
						stone[0][j] = 10+j;
					}
					a++;
				}else if((stone[i][2]==stone[i][3]) && (stone[i][3]==stone[i][4])){
					score += stone[i][2]*3;
					for(int j=i;j>0;j--){
						for(int k=2;k<5;k++){
							stone[j][k] = stone[j-1][k];
						}
					}
					for(int j=2;j<5;j++){
						stone[0][j] = 10+j;
					}
					a++;
				}
			}
		}
		cout<<score<<endl;
	}
	return 0;
}