#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <sstream>

using namespace std;

int const INT_MAX = 10000000;

bool map[100][100];

int main(){
	
	while(true){
		
		int n, m;
		
		cin >> n;
		
		if(n == 0){
			break;
		}
		
		for(int i = 0; i < 100; i++){
			for(int j = 0; j < 100; j++){
				map[i][j] = false;
			}
		}
		
		for(int i = 0; i < n; i++){
			int num1, num2;
			cin >> num1 >> num2;
			map[num1][num2] = true;
		}
		
		cin >> m;
		
		int pos_x = 10;
		int pos_y = 10;
		
		for(int loop = 0; loop < m; loop++){
			char c;
			int num;
			cin >> c >> num;
			for(int i = 0; i < num; i++){
				if(c == 'N'){
					pos_y++;
				}else if(c == 'S'){
					pos_y--;
				}else if(c == 'E'){
					pos_x++;
				}else{
					pos_x--;
				}
				map[pos_x][pos_y] = false;
			}
		}
		
		bool flag = true;
		
		for(int i = 0; i <= 20; i++){
			for(int j = 0; j <= 20; j++){
				if(map[i][j]){
					flag = false;
				}
			}
		}
		
		if(flag){
			cout << "Yes" << endl;
		}else{
			cout << "No" << endl;
		}
		
	}
	return 0;
}