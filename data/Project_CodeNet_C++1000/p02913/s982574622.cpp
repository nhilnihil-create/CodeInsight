#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <map>
using namespace std;
const long long MOD1 = 998244353;
const long long MOD2 = 1000000007;
const long long BASE = 1000000;
int main(){
	int N;
	cin >> N;
	string S;
	cin >> S;
	int tv = 0;
	int fv = N;
	while (fv - tv > 1){
		int mid = (tv + fv) / 2;
		vector<long long> hash1(N - mid + 1, 0);
		vector<long long> hash2(N - mid + 1, 0);
		for (int i = 0; i < N - mid + 1; i++){
			for (int j = 0; j < mid; j++){
				hash1[i] *= BASE;
				hash1[i] += S[i + j];
				hash1[i] %= MOD1;
				hash2[i] *= BASE;
				hash2[i] += S[i + j];
				hash2[i] %= MOD2;
			}
		}
		map<pair<int, int>, int> mp;
		bool ok = false;
		for (int i = 0; i < N - mid + 1; i++){
			if (mp.count(make_pair(hash1[i], hash2[i]))){
				if (i - mp[make_pair(hash1[i], hash2[i])] >= mid){
					ok = true;
				}
			} else {
				mp[make_pair(hash1[i], hash2[i])] = i;
			}
		}
		if (ok){
			tv = mid;
		} else {
			fv = mid;
		}
	}
	cout << tv << endl;
}