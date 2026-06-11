#pragma once
#include <string>
#include<iostream>
#include<stack>
#include<queue>
#include <vector>

#define rep(i,n) for(auto i=0;i<(n);i++)
#define all(container) (container).begin(),(container).end()

using namespace std;

int main() {
	string S, T;
	cin >> S >> T;
	int count = 0;
	rep(i, S.length()) {
		if (S[i] == T[i])count++;
	}
	cout << count << endl;
}
