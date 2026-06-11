
// E - League

// queueを用いた解法
// チェック対象を前日に試合があったプレイヤーに限定

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

queue<int> plan[1000];
set<pair<int, int>> games;
set<int> candidates; // 対戦を行う可能性のあるプレイヤー
set<int> next_candidates; // 次の日に対戦を行う可能性のあるプレイヤー

int main() {
	int N;
	cin >> N;

	int A;
	for (int i=0; i<N; i++) {
		for (int j=0; j<N-1; j++) {
			cin >> A;
			A--;
			plan[i].push(A);
		}

		candidates.insert(i);
	}

	int day = 0;
	while(!candidates.empty()) {
		day++;
		//cout << "day " << day << endl; // **** debug ****
		for (int a : candidates) {
			int b = plan[a].front();
			int c = plan[b].front();

			//cout << a+1 << "->" << b+1 << " " << b+1 << "->" << c+1 << endl; // **** debug ****

			if (a == c) {
				if (a > b) swap(a, b);
				//cout << "game: " << a+1 << " vs " << b+1 << endl; // **** debug ****
				games.insert(make_pair(a, b));
			}
		}

		for (auto p : games) {
			int a = p.first;
			int b = p.second;
			plan[a].pop();
			plan[b].pop();
			if (!plan[a].empty()) next_candidates.insert(a);
			if (!plan[b].empty()) next_candidates.insert(b);
		}

		games.clear();
		swap(candidates, next_candidates);
		next_candidates.clear();
	}

	bool finish = true;
	for (int i=0; i<N; i++) {
		if (!plan[i].empty()) {
			finish = false;
			break;
		}
	}

	int ans;
	if (finish) {
		ans = day;
	} else {
		ans = -1;
	}

	cout << ans << endl;

	return 0;
}