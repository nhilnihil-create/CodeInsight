#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;

#define repeat(i,n) for(int i=0;i<n;i++)
int *s;		//学生の点数を格納する配列
void solve(int n){
	double m = 0;
	double bunsan=0;
	s = new int[n];

	//点数入力
	repeat(i,n)
	{
		cin >> s[i];
	}

	//平均を求める
	repeat(i, n)
	{
		m += s[i];
	}
	m = m / n;
		//cout << m << endl;

	//分散を求める
	repeat(i, n)
	{
		bunsan += (s[i] - m)*(s[i] - m);
	}
	bunsan = bunsan / n;

	//出力
	cout << fixed << setprecision(5) << sqrt(bunsan) << endl;
	
	delete[] s;
	return ;
}

int main()
{
	int n;
	while (1)
	{
		cin >> n;
		if (n == 0) break;
		solve(n);
	}
	return 0;
}