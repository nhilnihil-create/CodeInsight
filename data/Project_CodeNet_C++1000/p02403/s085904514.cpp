#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;

void draw(int H,int W){
	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			cout << "#";
		}
		cout << endl;
	}
	return;
}

int main(){
	int H,W;
	for(int i=0;;i++){
		cin >> H >> W;
		if(H==0&&W==0)return 0;
		draw(H,W);
		cout <<endl;
	}

	return 0;
}