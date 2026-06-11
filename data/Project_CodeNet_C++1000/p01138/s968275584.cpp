
#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <math.h>

#define timemax 24*60*60 + 1
using namespace std;

int main(void){
	//FILE* fp_in = freopen("data.txt", "r", stdin);
	
	//imos法を用いる
	
	while(1) {
		int n;
		scanf("%d",&n);
		if( n == 0 ) break;
		vector<int> time;
		
		for(int i = 0; i < timemax; i++)
			time.push_back(0);

		for(int i = 0; i < n; i++) {
			for(int j = 0; j < 2; j++){
				int h,m,s;
				scanf("%02d:%02d:%02d", &h, &m, &s);
				if(j == 0) time.at(h*3600 + m*60 + s) ++;
				else time.at(h*3600 + m*60 + s) --;
			}
		}

		//最大値を求める
		int max = 0;
		for(int i = 1; i < time.size(); i++)
			time.at(i) += time.at( i - 1 );

		for(int i = 0; i < time.size(); i++)
			if( time.at(i) > max ) max = time.at(i);

		cout << max << endl;

	}

	
	//while(1){}
	return 0;
}