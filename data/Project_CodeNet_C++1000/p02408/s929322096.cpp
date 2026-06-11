#include<string>
#include<iostream>
#include<cctype>
#include<cmath>
#include<cstdio>

using namespace std;
int main(){

int a;
cin >> a;

char b[52];
int c[52];

int d[4][14];

for(int i=0;i<4;i++){
	for(int j=0;j<14;j++){
	d[i][j]=0;
	}
}

for(int i=0;i<a;i++){
	cin >> b[i] >> c[i];
	int n=c[i];
	if(b[i]=='S') d[0][c[i]]=1; 
	else if(b[i]=='H') d[1][n]=1;
	else if(b[i]=='C') d[2][n]=1;
	else d[3][n]=1;
}

for(int i=0;i<4;i++){
	for(int j=1;j<14;j++){
		if(d[i][j]==0){
			char ch;
			if(i == 0) ch = 'S';
                if(i == 1) ch = 'H';
                if(i == 2) ch = 'C';
                if(i == 3) ch = 'D';
                printf("%c %d\n", ch, j);
			}
	}
}

return 0;
}