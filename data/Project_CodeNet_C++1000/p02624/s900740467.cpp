#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include <deque>
#include <set>
using namespace std;

int main()
{
	int N;
	cin >> N;
	long long result = 0;
	for (int i = 1; i <= N; i++) {
		int a = N / i;
		long long b = (long long)i * (a)*(a + 1) / 2;
		result += b;
	}
	printf("%lld%",result);
	return 0;


}