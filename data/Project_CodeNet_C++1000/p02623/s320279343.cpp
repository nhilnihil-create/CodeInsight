#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<stack>
using namespace std;


int main() {
	long long int deskA, deskB, totalTime;
	cin >> deskA >> deskB >> totalTime;
	vector <long long int> timeA(deskA);
	vector <long long int> timeB(deskB);
	vector <long long int> prefixSumA(deskA + 1);
	vector <long long int> prefixSumB(deskB + 1);
	prefixSumA.push_back(0);
	prefixSumB.push_back(0);
	for (long long int i = 0; i < deskA; i++) {
		cin >> timeA[i];
		prefixSumA[i+1] = prefixSumA[i] + timeA[i];
	}
	for (long long int j = 0; j < deskB; j++) {
		cin >> timeB[j];
		prefixSumB[j+1] = prefixSumB[j] + timeB[j];
	}
	long long int maxBooks;;
	vector <long long int> result;
	long long int m = timeB.size();
	for (long long int i = 0; i < timeA.size()+1; i++) {
		long long int remainingTime = totalTime - prefixSumA[i];
		for (long long int j = m ; j >= 0; j--) {
			if (prefixSumA[i] + prefixSumB[j] <= totalTime) {
				m = j;
				result.push_back(i + j);
				break;
			}
		}
	}
	maxBooks = *max_element(result.begin(), result.end());
	cout << maxBooks;
	return 0;
}