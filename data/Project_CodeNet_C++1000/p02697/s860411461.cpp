#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main() {
	int m,n;
	cin >> n>>m;

	int h = n/2;
	if(n%2==1)h++;
	int x = h/2;
	int y = ((h +1)+n)/2 -1;

	int j =0;
	rep(i,m){
		cout << x << " " << x+i*2+1<<endl;
		x--;
		j++;
		if(j==m)break;
		cout << y << " " << y+i*2+1+1<<endl;
		y--;
		j++;
		if(j==m)break;
	}
	return 0;
}