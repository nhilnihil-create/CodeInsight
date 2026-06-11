#include<stdio.h>
#include <iomanip>
#include <iostream>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<algorithm>
#include <random>
#include <chrono>

#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
int main() {
	int n, k;
	cin >> n >> k;
	int tmp,cnt=0;
	rep(i, n) {
		cin >> tmp;
		if (tmp >= k) {
			cnt++;
		}
	}

	cout << cnt;

}