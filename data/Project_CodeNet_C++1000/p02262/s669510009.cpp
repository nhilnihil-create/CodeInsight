#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <stack>
using namespace std;
int n, m;
string s;
int cnt;
vector<int> v;
void insertionSort(int n, int h) {
	for (int i = h; i < n; ++i) {
		int w = v[i];
		int j = i - h;
		while (j >= 0 && v[j] > w) {
			v[j + h] = v[j];
			j = j - h;
			cnt++;
		}
		v[j + h] = w;
	}
}
int main() {
	cin >> n;
	
	for (int i = 0; i < n; ++i) {
		int a; cin >> a;
		v.push_back(a);
	}
	int m = 0;
	vector<int> h;
    int i=0;
	while(i<n){
        i=3*i+1;
        if(i>n) break;
        h.push_back(i);
        m++;
    }
	reverse(h.begin(), h.end());
	cout << m << endl;
	for (int i = 0; i < m; ++i) {
		if (i == m - 1) {
			cout << h[i] << endl;
			break;
		}
		cout << h[i] << " ";
	}
	
	for (int i = 0; i < m; ++i) {
		insertionSort(n, h[i]);
	}
	cout << cnt << endl;
	for (int i = 0; i < n; ++i) {
		cout << v[i] << endl;
	}
}
