#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

template<typename t1, class t2>
void input(t1 count,t2* array) {
	for(t1 i = 0;i < count;i++) {
		cin >> array[i];
	}
}

template<typename t1, class t2>
void output(t1 count,t2 array) {
	for(t1 i = 0;i < count;i++) {
		cout << array[i];
		if(i != count - 1) cout << " ";
	}
	cout << endl;
}

int insSort(int* a,int n,int g) {
	int cnt = 0;
	for(int i = g;i < n;i++) {
		int v = a[i];
		int j = i - g;
		while(j >= 0 && a[j] > v) {
			a[j+g] = a[j];
			j -= g;
			cnt++;
		}
		a[j+g] = v;
	}
	return cnt;
}

int main(int argc,char** argv) {
	int n;
	cin >> n;
	int t = n;
	vector<int> g;
	while(t != 0) {
		g.push_back(t);
		t = t / 2;
	}
	int m = (signed)g.size();
	int* a = new int[n];
	input(n,a);
	int cnt = 0;
	for(int i = 0;i < m;i++) {
		cnt += insSort(a,n,g[i]);
	}
	cout << m << endl;
	output(m,g);
	cout << cnt << endl;
	for(int i = 0;i < n;i++) cout << a[i] << endl;
	delete a;
}

