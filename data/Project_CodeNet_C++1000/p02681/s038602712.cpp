#include <stdio.h>
#pragma warning (disable:4996)

#define LANE 12

int main() {
	char S[LANE], T[LANE];
	(void)scanf("%s", S);
	(void)scanf("%s", T);
	bool ans = true;
	int i = 0;
	while (S[i] != '\0') {
		if (S[i] != T[i]) {
			ans = false;
		}
		i++;
	}
	if (T[i + 1] != '\0')ans = false;
	if (ans)printf("Yes"); else printf("No");
}

/*
#include <iostream>
#include <string>
#pragma warning (disable:4996)
using namespace std;

int main() {
	string S, T;
	scanf("%s", &S);
	scanf("%s", &T);
	int S_lane = sizeof(S) / sizeof(S.at(0));
	int T_lane = sizeof(T) / sizeof(T.at(0));
	bool ans = true;
	if (T_lane != S_lane + 1) ans = false;
	for (int i = 0; i < S_lane; i++) {
		if (S.at(i) != T.at(i)) {
			ans = false;
			break;
		}
	}
	if (ans == true)printf("Yes"); else printf("No");
}
*/