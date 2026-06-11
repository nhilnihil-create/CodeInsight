#include <iostream>
#include<cmath>
#include<vector>
 int insertion_sort(std::vector<int> &a, int n, int gap) {
	int count = 0;
	for (int i = gap; i < n; ++i) {
		int v = a[i];
		int j = i - gap;
		while (j >= 0 && a[j] > v) {
			a[j + gap] = a[j];
			j -= gap;
			count++;
		}
		a[j + gap] = v;
	}
	return count;
}
void shell_sort(std::vector<int>& a, int n) {
	std::vector< int>gaps(11, 1);
	for (int i = 1; i < 11; ++i) {
		gaps[i] = pow(4, i) + 3 * std::pow(2, i - 1) + 1;
	}
 //{ 1,8,23,77,281,1073,4193,16577,65921,262913,1050113 };
	
	int gap_num = 0, count = 0;
	while (gaps[gap_num + 1] < n) { gap_num++; }
	for (int i = gap_num; i >= 0; --i) { count += insertion_sort(a, n, gaps[i]); }
	std::cout << (gap_num + 1) << '\n';
	for (int i = gap_num; i; --i) std::cout << gaps[i] << ' ';
	std::cout << gaps[0] << '\n';
	std::cout << count << '\n';
}
int main(void) {
	std::ios::sync_with_stdio(false);
	int n;
	std::cin >> n;
	std::vector<int> a(n, 0);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
	shell_sort(a, n);
	for (int i = 0; i < n; ++i) { std::cout << a[i] << '\n'; }
}