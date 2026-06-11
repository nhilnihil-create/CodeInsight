#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;

int n;
int a[1000010];
long long cnt;

void insertionSort(int g){
	for(int i = g; i < n; ++i){
		int v = a[i];
		int j = i - g;
		while(j >= 0 && a[j] > v){
			a[j + g] = a[j];
			j = j - g;
			cnt++;
		}
		a[j + g] = v;
	}
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;

	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}

	cnt = 0;

	vector<int> G;
	int h = 1;
	while(1){
		if(h > n) break;
		G.push_back(h);
		h = 3 * h + 1;
	}

	for(int i = G.size() - 1; i >= 0; --i){
		insertionSort(G[i]);
	}

	cout << G.size() << endl;

	for(int i = G.size() - 1; i >= 0; --i){
		cout << G[i];
		if(i != 0)
			cout << " ";
		else
			cout << endl;
	}

	cout << cnt << endl;
	for(int i = 0; i < n; ++i){
		cout << a[i] << endl;
	}

	return 0;
}