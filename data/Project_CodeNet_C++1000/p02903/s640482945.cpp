#include <bits/stdc++.h>
using namespace std;

int main(){

	int h,w,a,b;cin >> h >> w >> a >> b;
	int t[h][w],i,j;

	for (i=0 ; i<h ; i++)
		for (j=0 ; j<w ; j++){
			if (i < h-b && j < a) t[i][j] = 1;
			else if (i >= h-b && j >= a) t[i][j] = 1;
			else t[i][j] = 0;
		}

	for (i=0 ; i<h ; i++){
		for (j=0 ; j<w ; j++) cout << t[i][j];

		cout << endl;
	}

	return 0;
}