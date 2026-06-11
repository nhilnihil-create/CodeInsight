#include <iostream>
#include <queue>
using namespace std;

int w, h, c, n;
int a[50][50];
queue<int> q;

void bfs() {
	int x, y;
	while (1) {
		x = q.front() % w;
		y = q.front() / w;
		
		if ( x > 0 && y > 0 && a[y - 1][x - 1] == 1 ) {
			a[y - 1][x - 1] = 0;
			q.push( ( y - 1 ) * w + x - 1 );
		}
		if ( x < w - 1 && y > 0 && a[y - 1][x + 1] == 1 ) {
			a[y - 1][x + 1] = 0;
			q.push( ( y - 1 ) * w + x + 1 );
		}
		if ( x > 0 && y < h - 1 && a[y + 1][x - 1] == 1 ) {
			a[y + 1][x - 1] = 0;
			q.push( ( y + 1 ) * w + x - 1 );
		}
		if ( x < w - 1 && y < h - 1 && a[y + 1][x + 1] == 1 ) {
			a[y + 1][x + 1] = 0;
			q.push( ( y + 1 ) * w + x + 1 );
		}
		if ( x > 0 && a[y][x - 1] == 1 ) {
			a[y][x - 1] = 0;
			q.push( y * w + x - 1 );
		}
		if ( y > 0 && a[y - 1][x] == 1 ) {
			a[y - 1][x] = 0;
			q.push( ( y - 1 ) * w + x );
		}
		if ( x < w - 1 && a[y][x + 1] == 1 ) {
			a[y][x + 1] = 0;
				q.push( y * w + x + 1 );
		}
		if ( y < h - 1 && a[y + 1][x] == 1 ) {
			a[y + 1][x] = 0;
			q.push( ( y + 1 ) * w + x );
		}
		q.pop();
		if ( q.empty() ) break;	
	}
	n++;
}

int main() {

	while (1) {
		n = 0;
		for ( int j = 0; j < 50; j++ )
			for ( int i = 0; i < 50; i++ )
				a[j][i] = 0;
		cin >> w >> h;
		if ( w == 0 ) break;
		for ( int j = 0; j < h; j++ ) {
			for ( int i = 0; i < w; i++ ) {
				cin >> c;
				a[j][i] = c;
			}
		}
		for ( int j = 0; j < h; j++ ) {
			for ( int i = 0; i < w; i++ ) {
				if ( a[j][i] == 1 ) {
					a[j][i] = 0;
					q.push( j * w + i );
					bfs();
				}
			}
		}
		cout << n << endl;
	}
}