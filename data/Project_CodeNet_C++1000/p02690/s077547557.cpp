#include <cstdio>
#include <map>
using namespace std;

const int T = 1000;

int main() 
{
	int x;
	scanf("%d", &x);
	for (int i = 0; i <= T; ++i) for (int j = -T; j <= i; ++j) if ((long long)i * i * i * i * i - (long long)j * j * j * j * j == x) {
		printf("%d %d\n", i, j);
		return 0;
	}
	return 0;
}
