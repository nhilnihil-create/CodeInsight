#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

int main()
{
	int N,K;
	cin >> N >> K;

	if (N < K) {
		cout << 1;
		return 0;
	}
	if (K == 1 || N ==K)
	{
		cout << 0;
		return 0;
	}
	
	if (N > K)
	{
		N -= K;
		cout << N;
		return 0;
	}
}
