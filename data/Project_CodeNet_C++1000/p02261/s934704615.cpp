#include <cstdio>
#include <iostream>
#include <utility>

using namespace std;

const int MAX_N = 40;
pair<char, int> cardB[MAX_N], cardS[MAX_N];
int N;
pair<char, int> pattern[MAX_N];

void show(pair<char, int> *C) {
	for (int i = 0; i < N; i++) {
		printf("%c%d", C[i].first, C[i].second);
		if (i != N - 1) {
			printf(" ");
		}
	}
	printf("\n");
}

void input() {
	/*char c;
	scanf("%d", &N);
	c = getc(stdin);
	for (int i = 0; i < N; i++) {
		scanf("%c%d", &cardB[i].first, &cardB[i].second);
		c = getc(stdin);
		cardS[i] = cardB[i];
		pattern[i] = cardB[i];
	}*/
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> cardB[i].first >> cardB[i].second;
		cardS[i] = cardB[i];
		pattern[i] = cardB[i];
	}
}

void BubbleSort(pair<char, int> *C, int n) {
	pair<char, int> temp;

	for (int i = 0; i < n; i++) {
		for (int j = n - 1; j >= 0; j--) {
			if (C[j].second < C[j - 1].second) {
				temp = C[j];
				C[j] = C[j - 1];
				C[j - 1] = temp;
			}
		}
	}
}

void SelectionSort(pair<char, int> *C, int n) {
	pair<char, int> temp;

	for (int i = 0; i < n; i++) {
		int minj = i;
		for (int j = i; j < n; j++) {
			if (C[j].second < C[minj].second) {
				minj = j;
			}
		}
		if (i != minj) {
			temp = C[i];
			C[i] = C[minj];
			C[minj] = temp;
		}
	}
}

void isStable(pair<char, int> *C) {
	bool f = true;

	for (int i = 0; i < N - 1; i++) {
		if (C[i].second == C[i + 1].second) {
			for (int j = 0; j < N; j++) {
				for (int k = 0; k < N; k++) {
					if (pattern[j] == C[i] && pattern[k] == C[i + 1]) {
						if (j > k) {
							f = false;
						}
					}
				}
			}
		}
	}
	if (f) {
		printf("Stable\n");
	}
	else {
		printf("Not stable\n");
	}
}

void solve() {
	input();
	BubbleSort(cardB, N);
	show(cardB);
	isStable(cardB);
	SelectionSort(cardS, N);
	show(cardS);
	isStable(cardS);
}

int main() {
	solve();
}