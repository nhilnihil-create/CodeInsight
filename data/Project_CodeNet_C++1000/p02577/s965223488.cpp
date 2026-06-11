#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define MAXN 500005
using namespace std;
int main()
{
	char c;
	long long ans = 0;
	while (scanf("%c", &c) != EOF && c != '\n') {
		ans += c - '0';
	}
	if (ans % 9 == 0) printf("Yes\n");
	else printf("No\n");
	return 0;
}