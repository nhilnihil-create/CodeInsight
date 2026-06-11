#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <cmath>
#include <cctype>

using namespace std;

int main()
{
	char W[10], T[100];
	int count = 0;

	cin >> W;

	while (1) {
		cin >> T;
		if (strcmp("END_OF_TEXT", T) == 0) break;
		int i = 0;
		while (T[i] != '\0') {
			if ('A' <= T[i] && T[i] <= 'Z') T[i] += 'a' - 'A';
			i++;
		} 

		if (strcmp(W, T) == 0) count++;
		
	}
	printf("%d\n", count);

	return (0);
}