#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<deque>
using namespace std;
#define ll long long
const int mod = 1000000007;
const ll INF = 1000000000000000000;


int main() 
{
	int W, H, x, y;
	cin >> W >> H >> x >> y;
	printf("%.10f ", (double)H * W / 2.0);
	if (x == (double)W / 2.0 && y == (double)H / 2.0) cout << 1 << endl;
	else cout << 0 << endl;

}
