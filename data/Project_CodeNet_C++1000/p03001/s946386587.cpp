#include<iostream>
#include<set>
#include<stack>
#include<queue>
#include<string>
#include<algorithm>//min,max,swap,rand,reverse,sort,lower_bound
#include<functional>
#include<vector>
#include<list>
#include<map>
#include<tuple>
#include<cmath>//abs, sin, cos
#include<bitset>
using namespace std;

int main()
{
	double W, H, x, y,ans;
	double S_x1, S_x2, S_y1, S_y2, S_x, S_y;
	cin >> W >> H >> x >> y;
	cout << double(W)*double(H) / 2 << endl;
	if (x + x == W && y + y == H)
		cout << '1';
	else
		cout << '0';
	return 0;
}