#include<bits/stdc++.h>
#define N 100007
int main() {
	int arr1[N]{};
	int arr11[N]{};
	int arr2[N]{};
	int arr22[N]{};
	int A, B, M, X, Y, C;
	std::cin >> A >> B >> M;
	for (int x = 0; x < A; x++)std::cin >> arr1[x],arr11[x]=arr1[x];
	for (int x = 0; x < B; x++)std::cin >> arr2[x],arr22[x]=arr2[x];

	std::sort(arr11, arr11 + A);
	std::sort(arr22, arr22 + B);
	int mn = 2000000;
	for (int x = 0; x < M; x++) {
		std::cin >> X >> Y >> C;
		mn=std::min((arr1[X-1] + arr2[Y-1] - C),mn);
	}
	mn = std::min((arr11[0] + arr22[0]), mn);
	std::cout << mn;
}