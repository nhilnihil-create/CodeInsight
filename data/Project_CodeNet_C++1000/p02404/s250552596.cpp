/*
 * hoge.cpp
 *
 *  Created on: 2014/09/30
 *      Author: eiichi
 */
#include<iostream>
#include<vector>
#include<cmath>
#include<string>
#include<map>
using namespace std;

void draw(int H,int W){
	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			if(i==0 || j==0 || i==H-1 || j==W-1){
				cout << "#";
			}
			else
				cout << ".";
		}
		cout << endl;
	}
}

int main(){
	int H,W;
	for(int i=0;;i++){
		cin >> H >> W;
		if(H==0 && W==0)return 0;
		draw(H,W);
		cout << endl;
	}

	return 0;
}