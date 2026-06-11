#include <iostream>
#include <utility>

using namespace std;

void output(int n, int elements[])
{
	for (int i = 0; i < n; i++)
		cout << elements[i] << '\n';
}

int insertion_sort(int n, int elements[], int g)
{
	int cnt = 0;
	for (int i = g; i < n; i++) {
		int key = elements[i],
			j = i - g;
		while (0 <= j && key < elements[j]) {
			elements[j + g] = elements[j];
			j -= g;
			cnt++;
		}
		elements[j + g] = key;
	}
	return cnt;
}

void shell_sort(int n, int elements[])
{
	int cnt = 0, m = 0, g[13] = { 1, 4, 13, 40, 121, 364, 1093, 3280, 9841, 29524, 88573, 265720, 797161 };
	
	for (; g[m] <= n && m < 13; m++);
	cout << m << '\n';
	for (int i = m - 1; 0 <= i; i--) {
		cout << g[i] << (i == 0 ? "" :  " ");
		cnt += insertion_sort(n, elements, g[i]);
	}
	cout << '\n';
	cout << cnt << '\n';
}

int main()
{
	std::ios::sync_with_stdio(false);

	int n;
	cin >> n;
	int *elements = new int[n];

	for (int i = 0; i < n; i++)
		cin >> elements[i];

	shell_sort(n, elements);
	output(n, elements);
	delete[] elements;
	return 0;
}