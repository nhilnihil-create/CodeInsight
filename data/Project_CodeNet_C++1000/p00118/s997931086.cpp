#include "bits/stdc++.h"
using namespace std;
char data[101][101];
bool flag[101][101] = { 0 };
int a, b;
int cnt;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int flag2=0;
int HH,WW;

int dfs(int H,int W,char C,int aa,int bb,int flag2){
	if(flag[H][W]==1){return flag2;}
	else{flag[H][W]=1;flag2=1;}
	for (int i = 0; i < 4; ++i) {
		HH=dy[i]+H;
		WW=dx[i]+W;
		if((HH>=0&&HH<aa&&WW>=0&&WW<bb)&&data[HH][WW]==C){
			dfs(HH,WW,C,aa,bb,flag2);
		}
	}
	return flag2;
}

int main(void) {
	while (cin >> a >> b) {
		if (a == 0 && b == 0) {
			break;
		}
		for (int i = 0; i < a; ++i) {
			cin >> data[i];
		}
		cnt=0;
		flag2=0;
		for (int i = 0; i < 101; ++i) {
			for (int j = 0; j < 101; ++j) {
				flag[i][j] = 0;
			}
		}

		for (int i = 0; i < a; ++i) {
			for (int j = 0; j < b; ++j) {
				if(dfs(i,j,data[i][j],a,b,0)==1)cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}