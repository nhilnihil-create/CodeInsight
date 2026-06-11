#include<iostream>
#include<algorithm>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)

int func(int X, int Y)
{
	int temp = X%Y;
	if (temp == 0)return Y;
	else func(Y, temp);
}

int main()
{
	int t1, t2,x,y;
	cin >> t1 >> t2;
	x = max(t1, t2);
	y = min(t1, t2);
	cout << func(x, y) << endl;
	return 0;
}