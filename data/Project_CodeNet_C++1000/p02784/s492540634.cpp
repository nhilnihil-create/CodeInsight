#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <stack>
#include <string>
#include <algorithm> 
#include <set>
#include <sstream>
#include <list>
#include <bit>
#include <bitset>
#include <cstdint>
#include <iomanip>
#include <queue>
#include <initializer_list>
#include <stdio.h>
typedef long long int ll;
using namespace std;
int main() {
	int H, N; cin >> H >> N;
	vector<int>data(N);
	for (int i = 0; i < N; i++)cin >> data[i];
	int sum = 0;
	for (int i = 0; i < N; i++)sum += data[i];
	if (H <= sum) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}