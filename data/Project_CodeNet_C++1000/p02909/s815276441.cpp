#include "bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

using namespace std;

int main() {
	string S;
	cin >> S;
	string weather[] = { "Sunny", "Cloudy", "Rainy" };
	if (S == weather[0])cout << weather[1];
	if (S == weather[1])cout << weather[2];
	if (S == weather[2])cout << weather[0];
}

