#include <iostream>
#include <vector>

using namespace std;

// unsigned int e[101];
// unsigned int d[101];
char e[101][2];
char d[101][2];

unsigned int cnt = 0;

void insertsort(unsigned int *d, unsigned int n, unsigned int g)
{
	for (unsigned int i = g; i < n; ++i) {
		unsigned int v = d[i];
		int j = i - g;
		while (j >= 0 && d[j] > v) {
			d[j+g] = d[j];
			j -= g;
			++cnt;
		}
		d[j+g] = v;
	}
}

void shellsort(unsigned int* d, unsigned int n)
{
	unsigned int m[101];
	unsigned int j = 1;
	unsigned int i;
	for (i = 0; i < n; ++i) {
		m[i] = j;
		j = j * 3 + 1;
		if (j >= n)
			break;
	}
	unsigned int mmax = i + 1;
	cout << mmax << "\n";
	cnt = 0;
	for (int i = mmax - 1; i > 0; --i) {
		cout << m[i] << " ";
		insertsort(d, n, m[i]);
	}
	cout << "1\n";
	insertsort(d, n, m[0]);
}

int main()
{
	unsigned int n;
	vector<unsigned int> s;
	cin >> n;
	s.resize(n);
	for (unsigned int i = 0; i < n; ++i) {
		cin >> s[i];
	}

	shellsort(&(s[0]), n);
	cout << cnt << "\n";
	for (unsigned int i = 0; i < n - 1; ++i) {
		cout << s[i] << "\n";
	}
	cout << s[n-1] << endl;

	return 0;
}

