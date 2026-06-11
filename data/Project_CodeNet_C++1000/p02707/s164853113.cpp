#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <numeric>
#include <math.h>

using namespace std;



void func()
{
	int N;
	cin >> N;
	vector<int> shain(N, 0);

	for (int i = 1; i < N; i++)
	{
		int Ai;
		cin >> Ai;
		shain[Ai-1]++;
	}
	for (int i = 0; i < N; i++)
	{
		cout << shain[i] << endl;
	}
}

int main() {

//	while (1)
		func();
	return 0;
}
