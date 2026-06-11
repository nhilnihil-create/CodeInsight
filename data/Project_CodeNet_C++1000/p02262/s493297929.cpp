#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define rep(i,from,to) for(int i=from; i<to; ++i)
#define REP(i,from,to) for(int i=from; i<=to; ++i)
using namespace std;
template<typename T>
ostream& operator<<(ostream& out, const vector<vector<T> >& v) {
	for (size_t i = 0; i < v.size(); ++i) {
		out << v[i] << endl;
	}
	return out;
}
template<typename T>
ostream& operator<<(ostream& out, const vector<T>& v) {
	out << "[";
	size_t last = v.size() - 1;
	for (size_t i = 0; i < v.size(); ++i) {
		out << v[i];
		if (i != last) {
			out << ",";
		}
	}
	out << "]";
	return out;
}
const int maxn = 1000100;
int n;
int c[maxn];
typedef pair<string, int> P;
void print(int arr[maxn], int n) {
	for (int i = 0; i < n - 1; ++i) {
		cout << arr[i] << " ";
	}
	cout << arr[n - 1] << endl;
}

void stable_bubble(P arr[maxn], int n) {
	int cnt = 0;
	int flag = 1;
	while (flag) {
		flag = 0;
		for (int j = n - 1; j >= 1; j--) {
			if (arr[j].first[1] < arr[j - 1].first[1]) {
				swap(arr[j], arr[j - 1]);
				flag = 1;
				cnt++;
			}
		}
	}
}

void stable_selection(P arr[maxn], int n) {
	int cnt = 0;
	REP(i,0,n-1)
	{
		int minj = i;
		REP(j,i,n-1)
		{
			if (arr[j].first[1] < arr[minj].first[1]) {
				minj = j;
			}
		}
		if (i != minj) {
			swap(arr[i], arr[minj]);
			cnt++;
		}
	}
}

void selectionSort(int arr[maxn], int n) {
	int cnt = 0;
	REP(i,0,n-1)
	{
		int minj = i;
		REP(j,i,n-1)
		{
			if (arr[j] < arr[minj]) {
				minj = j;
			}
		}
		if (i != minj) {
			swap(arr[i], arr[minj]);
			cnt++;
		}
	}
	print(arr, n);
	cout << cnt << endl;
}

void bubbleSort(int arr[maxn], int n) {
	int cnt = 0;
	int flag = 1;
	while (flag) {
		flag = 0;
		for (int j = n - 1; j >= 1; j--) {
			if (arr[j] < arr[j - 1]) {
				swap(arr[j], arr[j - 1]);
				flag = 1;
				cnt++;
			}
		}
	}
	print(arr, n);
	cout << cnt << endl;
}

void insertionSort(int arr[maxn], int n) {
	print(arr, n);
	REP(i,1,n-1)
	{
		int v = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > v) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = v;
		print(arr, n);
	}
}

int insertionSort(int arr[maxn], int n, int g) {
	int cnt = 0;
	REP(i, 0, n-1)
	{
		int v = arr[i];
		int j = i - g;
		while (j >= 0 && arr[j] > v) {
			arr[j + g] = arr[j];
			j = j - g;
			cnt++;
		}
		arr[j + g] = v;
	}
	return cnt;
}

int triRoot(int n) {
	int ret = 0;
	while (n > 1) {
		n /= 3;
		ret++;
	}
	return ret;
}
const int maxm = 100;
void shellSort(int arr[maxn], int n) {
	int cnt = 0;
	int g[maxm];
	int m = max(1, min(maxm, triRoot(n)));
	g[0] = 1;
	rep(i,1,m)
	{
		g[i] = g[i - 1] * 3 + 1;
	}
	std::reverse(g, g + m);

	rep(i,0,m)
	{
		cnt += insertionSort(arr, n, g[i]);
	}

	//print
	cout << m << endl;
	rep(i,0,m-1)
	{
		cout << g[i] << " ";
	}
	cout << g[m - 1] << endl;
	cout << cnt << endl;
	rep(i,0,n)
	{
		cout << arr[i] << endl;
	}
}

void solve() {
	cin >> n;
	rep(i,0,n)
	{
		cin >> c[i];
	}
	shellSort(c, n);
}

int main() {
	solve();
}