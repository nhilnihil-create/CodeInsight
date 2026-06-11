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
	string s,ans;
	cin >> s;
	if (s == "Sunny")ans = "Cloudy";
	else if (s == "Cloudy")ans = "Rainy";
	else ans = "Sunny";
	cout << ans;

}