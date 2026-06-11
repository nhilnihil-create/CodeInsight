#include<iostream>
using namespace std;

void dispStone(int stone[][5]){
	for(int i=9;i>=0;i--){
		for(int j=0;j<5;j++){
			cout<<stone[i][j];
		}
		cout<<endl;
	}
	cout<<endl;
}

bool isStoneDrop(int stone[][5]){
	for(int i=0;i<5;i++){
		bool flg=true;
		for(int j=0;j<10;j++){
			if(stone[j][i]==0) flg=false;
			else if(flg==false && stone[j][i]!=0) return true;
		}
	}
	return false; //これ以上落ちない
}
void drop(int stone[][5]){
	while(isStoneDrop(stone)){
		for(int i=0;i<9;i++){
			for(int j=0;j<5;j++){
				if(stone[i][j]==0 && stone[i+1][j]!=0){
					stone[i][j]=stone[i+1][j];
					stone[i+1][j]=0;
				}
			}
		}
	}
}
bool isStone(int *stone_line){
	for(int i=0;i<5;i++){
		if(stone_line[i]!=0){
			return true;
		}
	}
	return false;
}
int checkLine(int *stone_line){
	int point=0;
	int chain=0;
	for(int i=0;i<4;i++){
		if(chain>1 && stone_line[i]!=stone_line[i+1]){
			for(;chain>=0;chain--){
				point+=stone_line[i-chain];
				stone_line[i-chain]=0;
			}
			return point;
		}else if(stone_line[i]==stone_line[i+1]){
			chain++;
		}else{
			chain=0;
		}
	}
	if(chain>1){
		for(chain;chain>=0;chain--){
			point+=stone_line[4-chain];
			stone_line[4-chain]=0;
		}	
			return point;
	}else{
		return 0;
	}
}
int erase(int stone[][5]){
	int point=0,i=0;
	while(isStone(stone[i])){
		point+=checkLine(stone[i]);
		i++;
	}
	return point;
}


int main(){
	int h;
	cin>>h;
	while(h!=0){
		int point=0;
		int stone[10][5]={};
		for(int i=0;i<h;i++){
			for(int j=0;j<5;j++){
				cin>>stone[h-i-1][j];
			}
		}
		while(1){
			if(int p=erase(stone)){
				point+=p;
//dispStone(stone);
			}else{
				break;
			}
			drop(stone);
//dispStone(stone);
		}
		cout<<point<<endl;
		cin>>h;
	}

	return 0;
}