#include "bits/stdc++.h"
using namespace std;
int main() {
	int X,Y,A,B,C;
	cin >> X >> Y >> A >> B >> C; 
	multiset<long long>AppleA; 
	multiset<long long>AppleB;
	multiset<long long>Apple;
	for (int n = 0;n<A;++n) {
		long long  num;
		cin >> num;
		AppleA.insert(num);
	}
	for (int n = 0; n < B; ++n) {
		long long num;
		cin >> num;
		AppleB.insert(num);
	}
	{
		int count = 0;
		for (auto itr = AppleA.begin(); itr != AppleA.end(); ++itr) {
			if (count >= A-X) {
				Apple.insert(*itr);
			}
			count++;
		}
	}
	{
		int count = 0;
		for (auto itr = AppleB.begin(); itr != AppleB.end(); ++itr) {
			if (count >= B-Y) {
				Apple.insert(*itr);
			}
			count++;
		}
	}
	for (int n = 0; n < C; ++n) {
		long long num;
		cin >> num;
		Apple.insert(num);
	}
	long long ans = 0;
	int count = 0;
	for (auto itr = Apple.begin(); itr != Apple.end(); ++itr){
		if (count >= C) {
			ans += *itr;
		}
		count++;
	}
	cout <<ans << endl;
	return 0;
}
