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

	int a, b, c,empty;
	int ans;
	cin >> a >> b >> c;
	empty = a - b;
	ans = c - empty;
	ans = max(ans, 0);
	cout << ans;

}