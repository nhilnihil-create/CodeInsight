#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <deque>
#include <map>
const int MOD = 1e9+7;
typedef long long ll;
using namespace std;

vector<int> moji[26];

int ctoi(char c){
	return c - 'a';
}

int main(){
	string s, t;
	cin >> s >> t;

	s += s;
	
	for (int i = 0; i < s.length(); i++){
		moji[ctoi(s[i])].push_back(i+1);
	}

	ll ans = 0;
	int now = 0, j = 0;
	for (int i = 0; i < t.length(); i++){
		if (moji[ctoi(t[i])].size() == 0){
			cout << -1 << endl;
			return 0;
		}

		auto iter = lower_bound(moji[ctoi(t[i])].begin(), moji[ctoi(t[i])].end(), now+1);
		ans = j*s.length()/2 + *iter;
		if (*iter >= s.length()/2){
			now = *iter - s.length()/2;
			j++;
		}else{
			now = *iter;
		}
	}
	cout << ans << endl;
	return 0;
}
