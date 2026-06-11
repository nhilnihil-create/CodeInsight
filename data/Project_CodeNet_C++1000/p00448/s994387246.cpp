#include <iostream>
#include <cstring>
using namespace std;

const int H = 10, W = 10000;
int state[H][W];
int cstate[H][W];

int main(){
	int lim, r, c, p, max, tmp, count;
	while(cin >> r >> c, r != 0, c != 0){
		lim = 1;
		max = p = 0;
		for(int i = 0;i < r;++i){
			lim *= 2;
		}
		for(int i = 0;i < r;++i){
			for(int j = 0;j < c;++j){
				cin >> state[i][j];
			}
		}
		while(p < lim){
			tmp = p;
			count = 0;
			int a, b;
			for(int i = 0;i < r;++i){
				for(int j = 0;j < c;++j){
					if(tmp % 2)	cstate[i][j] = 1 - state[i][j];
					else cstate[i][j] = state[i][j];
				}
				tmp /= 2;
			}
			for(int j = 0;j < c;++j){
				a = b = 0;
				for(int i = 0;i < r;++i){
					if(cstate[i][j]) ++a;
					else ++b;
				}
				if(b - a > 0) count += b;
				else count += a;
			}
			max = count > max ? count : max;
			p += 1;
		}
		cout << max << endl;
	}
	return 0;
}