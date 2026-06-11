/*
分析 f[x] = ans
f1 = f2 = 0
f3 = 1
f4 = 1
f5 = 1
f6 = 2
f7 = 3
f8 = 4
f9 = 6
f10 = f9 + f7 = 9;
*/
/*
*/
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int N = 1e9 + 7;
int s, f[2005];
int main()
{
	scanf("%d", &s);
	f[3] = 1;
	for(int i = 4; i <= s; i ++)
		f[i] = ( f[i - 3] + f[i - 1] ) % N;
	printf("%d", f[s]);
}