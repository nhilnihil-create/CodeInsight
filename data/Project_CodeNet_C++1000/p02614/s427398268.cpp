#include<iostream>

using namespace std;
int h,w,k;
char grid[10][10];
int count(){
	int c = 0;
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			if(grid[i][j]=='#')c++;
		}
	}
	return c;
}

void color(char c,int n){
	if(c=='r'){
		for(int i=0;i<w;i++){
			if(grid[n][i]=='#')grid[n][i] = 'c';
		}
	}
	else{
		for(int i=0;i<h;i++){
			if(grid[i][n]=='#')grid[i][n] = 'c';
		}
	}
}

void reverse(){
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			if(grid[i][j]=='c')grid[i][j] = '#';
		}
	}
}



int main(){
int flag = 0;
cin >> h >> w >> k;
char c;
for(int i=0;i<h;i++){
	scanf("%s%c",grid[i],&c);
}

//subset
int total = h + w;
for(int i=0;i<1<<total;i++){
	for(int j=0;j<total;j++){
		if(i & 1<<j){
			if(j>=h){
				int index = j - h;
				color('c',index);
			}
			else color('r',j);

		}
	}
	int ko = count();
	if(ko == k){
		/*for(int i=0;i<h;i++)printf("%s\n",grid[i]);
			printf("\n");*/
		flag++;
	}
	reverse();
}


printf("%d\n",flag);

	return 0;
}