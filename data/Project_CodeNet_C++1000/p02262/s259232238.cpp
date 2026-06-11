#include <iostream>
#include <string>
#include <vector>

int cnt = 0;

void insertionSort(int arr[], int n, int g) {

	for (int i = g; i < n; ++i) {
		int v = arr[i];
		int j = i - g;
		while (j >= 0 && arr[j] > v) {
			arr[j + g] = arr[j];
			j = j - g;
			++cnt;
		}
		arr[j + g] = v;
	}

}

void shellSort(int arr[], int n) {

	std::vector<int> G;
	int h = 1;
	while (h <= n) {
		G.push_back(h);
		h = h * 3 + 1;
	}
	for (int i = 1; i < n; i = i * 3 + 1) {
	}
	std::cout << G.size() << std::endl;

	int i = 0;
	std::vector<int>::reverse_iterator it = G.rbegin();
	while (it != G.rend()) {
		insertionSort(arr, n, *it);
		if (i != 0) {
			std::cout << " ";
		}
		std::cout << *it;
		++i;
		++it;
	}
	std::cout << std::endl;
}

int main() {

	int n;
	std::cin >> n;

	int arr[n];
	for (int i = 0; i < n; ++i) {
		std::cin >> arr[i];
	}

	shellSort(arr, n);

	std::cout << cnt << std::endl;

	for (int i = 0; i < n; ++i) {
		std::cout << arr[i] << std::endl;
	}

	return 0;
}