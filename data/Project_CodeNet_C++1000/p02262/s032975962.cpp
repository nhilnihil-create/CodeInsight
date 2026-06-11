#include <iostream>
#include <vector>

using namespace std;

int cnt;

void insertionSort(int* a,int n,int g) {
	for(int i = g;i < n;i++) {
		int v = a[i];
		int j = i - g;
		while(j >= 0&& a[j]>v){
			a[j+g]=a[j];
			j=j-g;
			cnt++;
		}
		a[j+g]=v;
	}
}

void shellSort(int* a,int n) {
	vector<int> g;
	int t = n;
	while(t > 0) {
		g.push_back(t);
		t = t / 2;
	}
	cout << g.size() << endl;
	for(int i = 0;i < g.size()-1;i++) {
		cout << g[i] << " ";
	}
	cout << g[g.size()-1] << endl;
	for(auto e:g) {
		insertionSort(a,n,e);
	}
	cout << cnt << endl;
	for(int i = 0;i < n;i++) {
		cout << a[i] << endl;
	}
}

int main() {
	int n,a[1000000];
	cin >> n;
	for(int i = 0;i < n;i++) cin >> a[i];
	shellSort(a,n);
}

