#include <iostream>
#include <vector>

using namespace std;

int insertion_sort(vector<int> *vec, int n, int g)
{
	auto cnt = 0;
	for (int i=g; i<n; i++) {
		int v = (*vec)[i];
		int j = i - g;
		while (j >= 0 && (*vec)[j] > v) {
			(*vec)[j+g] = (*vec)[j];
			j -= g;
			cnt++;
		}
		(*vec)[j+g] = v;
	}
	return cnt;
}

void shell_sort(vector<int> vec, int n)
{
	int cnt=0, m = 1;
	vector<int> g = {1};
	while (2*g.back()+1 < n) {
		m++;
		g.push_back(2*g.back()+1);
	}

	for (int i=m-1; i>=0; i--)
		cnt += insertion_sort(&vec, n, g[i]);
	
	cout << m << endl;
	for (int i=m-1; i>0; i--)
		cout << g[i] << " ";
	cout << g[0] << endl
	     << cnt << endl;
	for (int i=0; i<n; i++)
		cout << vec[i] << endl;
}

int main(void)
{
	int n;
	vector<int> vec;
	cin >> n;
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		vec.push_back(x);
	}

	shell_sort(vec, n);

	return 0;
}