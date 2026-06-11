#include <iostream>
#include <queue>
#define intt long long

int main(){
	intt N, M; intt ans{}; std::cin >> N >> M;
	std::priority_queue<intt> que;
	for (intt i = 0; i < N; ++i) { intt a; std::cin >> a; que.push(a); }
	for (intt i = 0; i < M; ++i) { intt b = que.top(); que.pop(); que.push(b / 2); }
	while (!que.empty()) { ans += que.top(); que.pop(); }
	std::cout << ans << std::endl;

	return 0;
}