#include <iostream>
#include <string>
#include <typeinfo>

struct Card {
	char suit;
	int value;
};

void traceALDS12C(Card arr[], int max) {
	for (int i = 0; i < max; ++i) {
		if (i)
			std::cout << " ";
		std::cout << arr[i].suit << arr[i].value;
	}
	std::cout << std::endl;
}

void BubbleSort(Card arr[], int N) {

	for (int i = 0; i < N; ++i) {
		for (int j = N - 1; j > i; --j) {
			if (arr[j - 1].value > arr[j].value) {
				std::swap(arr[j - 1], arr[j]);
			}
		}
	}
	traceALDS12C(arr, N);
	std::cout << "Stable" << std::endl;
}

void SelectionSort(Card arr[], int N) {

	for (int i = 0; i < N; ++i) {
		int minIdx = i;
		for (int j = i; j < N; ++j) {
			if (arr[minIdx].value > arr[j].value) {
				minIdx = j;
			}
		}
		if (minIdx != i) {
			std::swap(arr[minIdx], arr[i]);
		}
	}
	traceALDS12C(arr, N);
}

bool check(Card str1[], Card str2[], int N) {
	for (int i = 0; i < N; ++i) {
		if (str1[i].suit != str2[i].suit || str1[i].value != str2[i].value) {
			return false;
		}
	}
	return true;
}

int main() {

	int N;
	std::cin >> N;

	Card cards[N];
	for (int i = 0; i < N; ++i) {
		std::cin >> cards[i].suit >> cards[i].value;
	}

	Card cards2[N];
	for (int i = 0; i < N; ++i)
		cards2[i] = cards[i];

	BubbleSort(cards, N);
	SelectionSort(cards2, N);

	if (check(cards, cards2, N)) {
		std::cout << "Stable" << std::endl;
	} else {
		std::cout << "Not stable" << std::endl;
	}

	return 0;
}