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
	int n;
	double sum=0;
	double tmp;
	cin >> n;
	
	rep(i, n) {
		cin >> tmp;
		sum += 1 / tmp;
	}
	cout << setprecision(30)<< 1 / sum;

}