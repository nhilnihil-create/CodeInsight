#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <fstream>
#include <queue>

#pragma warning( disable: 4996 )

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

#define INF 1000000000
#define EPS 1e-10

#define MAX_N 10000

ll N, M;
P p[MAX_N];
vector<ll> ans_list;

int main(){

	while (true){

		cin >> N >> M;
		if (N == 0 && M == 0)
			break;

		for (int i = 0; i < N; i++){
			cin >> p[i].second >> p[i].first;
		}

		sort(p, p + N);

		ll ans = 0;

		for (int i = N-1; i >= 0; i--){
			if (p[i].second <= M){
				M -= p[i].second;
			}
			else{
				p[i].second -= M;
				M = 0;
				ans += p[i].first * p[i].second;
			}
		}

		ans_list.push_back(ans);

	}

	for (int i = 0; i < ans_list.size(); i++){
		cout << ans_list[i] << endl;
	}

	return 0;

}