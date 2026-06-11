#include<iostream>
#include<vector>
#include<algorithm>
int main(void) {
	int n, q;
	std::cin >> n;
	if (n == 0) { std::cout << 0 << std::endl; return 0; }
	std::vector<long>S(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> S[i];
	}
	std::sort(S.begin(), S.end());
	std::cin >> q;
	if (q == 0) { std::cout << 0 << std::endl; return 0; }
	std::vector<long>T(q);
	for (int i = 0; i < q; ++i) {
		std::cin >> T[i];
	}
	std::sort(T.begin(), T.end());
	int cnt = 0;
	for (int i = 0; i < q; ++i) {
		std::vector<long>::iterator itr= std::find(S.begin(),S.end(), T[i]);
		if (std::binary_search(itr, S.end(), T[i]))
		{
			cnt++;
			itr++;
		}
	}
	std::cout << cnt << std::endl;
	//	system("pause");
	return 0;
}