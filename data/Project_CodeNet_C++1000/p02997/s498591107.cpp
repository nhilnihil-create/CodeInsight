#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>
#include<set>
#include<math.h>

#define DIV 1000000007
using namespace std;
using ll = long long;

int main(void) {
	int N, K;
	cin >> N >> K;
	
	int mx = (N - 1) * (N - 2) / 2;
	if (K > mx)
		cout << -1 << endl;
	else {
		int rem = mx - K;
		cout << (N - 1) + rem << endl;
		for (int i = 2; i <= N; i++)
			cout << 1 << " " << i << endl;


		for (int i = 2; rem > 0; i++) {
			for (int j = i + 1; j <= N && rem>0; j++) {
				cout << i << " " << j << endl;
				rem--;
			}
		}
	}
}
