#include "bits/stdc++.h"
using namespace std;
#define rep(i,n)for(int i=0;i<(int)(n);i++)
#define PI 3.141592653589793
//vector < vector<int>>a(0, vector<int>(0));二次元配列宣言


int main()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	int i;
	for (i = 0; i < s.length(); i++)
	{
		int a;
		a = s.at(i) + n;
		//cout << a << endl;
		if (a > int('Z'))
		{
			a = 'A'-1 +a % int('Z');
		}
		s.at(i) = char(a);
	}
	cout << s<<endl;
}