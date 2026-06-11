#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);
	map<string, int> vote;
	for (int i = 0; i < N; i++) {
		string S;
		cin >> S;
		vote[S]++;
	}
	int maxVote = 0;
	for (auto itr = vote.begin(); itr != vote.end(); itr++) {
		maxVote = max(maxVote, itr->second);
	}
	for (auto itr = vote.begin(); itr != vote.end(); itr++) {
		if (itr->second == maxVote) {
			cout << itr->first << endl;
		}
	}

	return 0;
}
