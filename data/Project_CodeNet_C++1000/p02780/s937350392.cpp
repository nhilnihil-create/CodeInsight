#include <bits/stdc++.h>
#include <algorithm>  
#include <unordered_set>
#include <cmath>
#define ll long long
using namespace std;


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, K;


	cin >> N >> K;

	vector<int> p(N + 1);

	for (int i = 1; i <= N; i++) {
		cin >> p[i];
	}
	
	double maxProb = 0;

	vector<double> probs = { 0, 0 };

	for (int i = 1; i <= N; i++) {
		probs.push_back(probs.back() + (double)((p[i] * (p[i] + 1)) / (double)2.0)* (1 / ((double)p[i])));
	}

	for (int i = 1; i <= probs.size() - K - 1; i++) {
		maxProb = max(probs[i + K] - probs[i], maxProb);
	}

	cout << fixed << std::setprecision(6) << maxProb << endl;

	/*
	
	
	for (int i = 1; i <= N - K + 1; i++) {

		double eachProb = 0;

		for (int j = i; j < i + K; j++) {
			eachProb += (double)((p[j] * (p[j] + 1)) / (double)2.0) * (1 / ((double)p[j]));
		}

		maxProb = max(eachProb, maxProb);
	}

	cout << fixed << std::setprecision(6) << maxProb << endl; */
	
	return 0;
}