#include<bits/stdc++.h>
#define NN 1000090
bool arr[NN]{};
int main() {
	int num; std::cin >> num;
	for (int x = 0; x < NN; x++)arr[x] = 1;

	for (int x = 2; x <= num+100; x++) {
		if (arr[x]) {
			for (int z = x + x; z <= num+100; z+=x) {
				arr[z] = 0;
			}
		}
	}

	if (arr[num]) std::cout << num;
	else {
		int a = num + 1;
		while (!arr[a]) { a++; };
		std::cout << a;
	}
}