#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{	
	//??\???1
	int n = 0;
	cin >> n;

	vector < int > v_m;
	v_m.resize(n);
	for(int i = 0; i < n; ++i)
	{
		cin >> v_m[i];
	}

	//?????§????????????
	int s_max = -2000000000;
	int s_min = v_m[0];
	for(int i = 1; i < n; ++i)//???
	{
		s_max = max(s_max,v_m[i]-s_min);
		s_min = min(s_min,v_m[i]);
	}

	cout << s_max << endl;
	return 0;
}