#include <iostream>
#include <stack>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

#define rep(i,n) for(int i=0; i < n; i++)
using ll =  long long;
using namespace std;
#define pi 3.14159265358979

int main()
{
	int n, point, question;
	cin >> n >> point >> question;
	vector<int> p(n, point -  question);

	rep(i, question)
	{
		int x;
		cin >> x;
		p[x-1]++;
	}

	rep(i, n)
	{
		if (p[i] > 0) cout << "Yes" << endl;
		else          cout << "No"  << endl;
	}
	return 0;
}