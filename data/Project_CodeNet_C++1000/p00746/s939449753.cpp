#include<iostream>
#include<algorithm>
using namespace std;

#define rep(i,n) for(int i=0; i<n; i++)

int main(){
	int N;
	while( cin >> N, N ){
		int pos[200][2] = {};
		for(int i=1; i<N; i++){
			int n, d;
			cin >> n >> d;
			pos[i][0] = pos[n][0];
			pos[i][1] = pos[n][1];
			pos[i][d%2] += (d<2 ? -1 : 1);
		}
		int minX=0, maxX=0, minY=0, maxY=0;
		for(int i=1; i<N; i++){
			if( pos[i][0] > maxX )	maxX = pos[i][0];
			if( pos[i][0] < minX )	minX = pos[i][0];
			if( pos[i][1] > maxY )	maxY = pos[i][1];
			if( pos[i][1] < minY )	minY = pos[i][1];
		}
		cout << (maxX-minX+1) << " " << (maxY-minY+1) << endl;
	}
	return 0;
}