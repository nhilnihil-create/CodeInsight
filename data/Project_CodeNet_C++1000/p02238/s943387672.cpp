#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <utility>
#include <climits>
#include <cstring>
#include <cstdio>

using namespace std;
typedef long long int llg;

const int INF = 1000001000;
#define REP(var, count) for(int var=0; var<count; var++)

template <typename T>
using reverse_queue = std::priority_queue<T, std::vector<T>, std::greater<T> >;

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
	std::fill( (T*)array, (T*)(array+N), val );
}

vector<int> rin[105];
pair<int, int> res[105];

int dfs(int a, int time) {
	res[a].first = time;
	for ( int r : rin[a] ) {
		if ( res[r].first != -1 ) { continue; }
		time = dfs(r, time + 1);
	}
	res[a].second = time + 1;
	return res[a].second;
}

int main(void) {
	int N;
	cin >> N;
	
	for(int i=1; i<=N; i++) {
		rin[0].push_back(i);
	
		res[i].first = -1;
		res[i].second = -1;
		
		int U, K;
		cin >> U >> K;
		REP(j, K) {
			int x;
			cin >> x;
			rin[U].push_back(x);
		}
	}
	
	dfs(0, 0);
	
	for(int i=1; i<=N; i++) {
		printf("%d %d %d\n", i, res[i].first, res[i].second);
	}
}