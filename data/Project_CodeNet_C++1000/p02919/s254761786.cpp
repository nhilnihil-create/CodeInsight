#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <limits>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <functional>

using namespace std;

using ll = long long;
using vll = std::vector<ll>;
using vvll = std::vector<vll>;
using vvvll = std::vector<vvll>; 
#define reps(i, S, E) for (ll i = (S); i <= (E); i++)
#define rep(i, N) reps(i, 0, N-1)
#define deps(i, E, S) for (ll i = (E); i >= (S); i--)
#define dep(i, N) deps(i, N-1, 0)

const ll MOD = 1000000007;
const ll INF = 1LL << 60;

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif


//140 Second Sum
int main() {
	ll N;
	scanf("%lld", &N);
	vector<ll> P(N);
	vector<ll> I(N + 1);
	for (ll i = 0; i < N; i++) {
		scanf("%lld", &P[i]);
		I[P[i]] = i;
	}

	set<ll> finishedIndex;
	finishedIndex.insert(I[N]);

	ll result = 0;
	deps(i, N - 1, 1) {
		ll target = I[i];
		ll left1 = -1;
		ll left2 = -1;
		ll right1 = N;
		ll right2 = N;

		auto it_left1 = finishedIndex.lower_bound(target);
		if (it_left1 != finishedIndex.begin()) {
			it_left1--;
			left1 = *it_left1;

			auto it_left2 = finishedIndex.lower_bound(left1);
			if (it_left2 != finishedIndex.begin()) {
				it_left2--;
				left2 = *it_left2;
			}
		}

		auto it_right1 = finishedIndex.upper_bound(target);
		if (it_right1 != finishedIndex.end()) {
			right1 = *it_right1;

			auto it_right2 = finishedIndex.upper_bound(right1);
			if (it_right2 != finishedIndex.end()) {
				right2 = *it_right2;
			}
		}

		eprintf("i:%lld\n", i);
		eprintf("target:%lld\n", target);
		eprintf("left2 left1:%lld %lld\n", left2, left1);
		eprintf("right1 right2:%lld %lld\n", right1, right2);


		//with left
		if (left1 >= 0) {
			ll leftCount = left1 - left2;
			ll rightCount = right1 - target;

			result += (leftCount * rightCount) * i;
		}

		//with right
		if (right1 < N) {
			ll leftCount = target - left1;
			ll rightCount = right2 - right1;

			result += (leftCount * rightCount) * i;
		}

		finishedIndex.insert(I[i]);
	}

	printf("%lld\n", result);
}


//143 Travel by Car
/*
int main() {
	ll N;
	scanf("%lld", &N);
	ll M;
	scanf("%lld", &M);
	ll L;
	scanf("%lld", &L);

	vvll graph(N, vll(N, INF));
	rep(i, M) {
		ll A;
		scanf("%lld", &A);
		ll B;
		scanf("%lld", &B);
		ll C;
		scanf("%lld", &C);
		A--;
		B--;

		graph[A][B] = C;
		graph[B][A] = C;
	}

	ll Q;
	scanf("%lld", &Q);
	vll s(Q);
	vll t(Q);
	rep(i, Q) {
		scanf("%lld", &s[i]);
		scanf("%lld", &t[i]);
		s[i]--;
		t[i]--;
	}

	vvll dist(N, vll(N, INF));
	rep(j, N) rep(i, N) {
		if (i == j) {
			dist[i][j] = 0;
		}
		else {
			dist[j][i] = graph[j][i];
		}
	}

	//�S���_�Ԃ̋��������߂�O(N^3)
	rep(i, N) rep(j, N) rep(k, N) { // �o�R���钸�_-�J�n���_-�I�[
		dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
	}

	vvll once(N, vll(N, INF));
	rep(j, N) rep(i, N) {
		if (i == j) {
			once[i][j] = 0;
		}
		else {
			once[j][i] = dist[j][i] <= L ? 1ll : INF;
		}
	}

	eprintf("once:\n");
	rep(j, N) {
		rep(i, N) {
			once[j][i] == INF ? eprintf("- ") : eprintf("%lld ", once[j][i]);
		}
		eprintf("\n");
	}

	rep(i, N) rep(j, N) rep(k, N) {
		once[j][k] = min(once[j][k], once[j][i] + once[i][k]);
	}

	//debug
	eprintf("graph:\n");
	rep(j, N) {
		rep(i, N) {
			graph[j][i] == INF ? eprintf("- ") : eprintf("%lld ", graph[j][i]);
		}
		eprintf("\n");
	}
	eprintf("dist:\n");
	rep(j, N) {
		rep(i, N) {
			dist[j][i] == INF ? eprintf("- ") : eprintf("%lld ", dist[j][i]);
		}
		eprintf("\n");
	}
	eprintf("once:\n");
	rep(j, N) {
		rep(i, N) {
			once[j][i] == INF ? eprintf("- ") : eprintf("%lld ", once[j][i]);
		}
		eprintf("\n");
	}
	eprintf("result:\n");

	rep(i, Q) {
		eprintf("%lld -> %lld: ", s[i], t[i]);
		if (once[s[i]][t[i]] == INF) {
			printf("-1\n");
		}
		else {
			printf("%lld\n", once[s[i]][t[i]] - 1);
		}
	}
}
*/


//130 Common Subsequence
/*
int main() {
	ll N;
	scanf("%lld", &N);
	ll M;
	scanf("%lld", &M);
	vector<ll> S(N + 1);
	for (ll i = 0; i < N; i++) {
		scanf("%lld", &S[i]);
	}
	vector<ll> T(M + 1);
	for (ll i = 0; i < M; i++) {
		scanf("%lld", &T[i]);
	}

	vector<vector<ll>> dp0(N + 2, vector<ll>(M + 2, 0));
	vector<vector<ll>> dp1(N + 2, vector<ll>(M + 2, 0));
	dp0[0][0] = 1;

	for (ll j = 0; j <= M; j++) {
		for (ll i = 0; i <= N; i++) {
			dp0[i + 1][j] += dp0[i][j];
			dp1[i][j] += dp0[i][j];
			dp1[i][j + 1] += dp1[i][j];

			if (S[i] == T[j]) {
				dp0[i + 1][j + 1] += dp1[i][j];
				dp0[i + 1][j + 1] %= MOD;
			}

			dp0[i + 1][j] %= MOD;
			dp1[i][j] %= MOD;
			dp1[i][j + 1] %= MOD;
		}
	}

	//for (ll j = 0; j <= M; j++) {
	//	for (ll i = 0; i <= N; i++) {
	//		printf("[%lld][%lld]: %lld %lld\n", i, j, dp0[i][j], dp1[i][j]);
	//	}
	//}

	printf("%lld\n", dp1[N][M]);
}
*/

//132 Hopscotch Addict
/*
struct LLPair {
	ll node = 0;
	ll dist = 0;
	LLPair() {}
	LLPair(int node, int dist) {
		this->node = node;
		this->dist = dist;
	}
};

int main() {
	ll N;
	scanf("%lld", &N);
	ll M;
	scanf("%lld", &M);
	vector<ll> u(M);
	vector<ll> v(M);
	for (ll i = 0; i < M; i++) {
		scanf("%lld", &u[i]);
		scanf("%lld", &v[i]);
		u[i]--;
		v[i]--;
	}
	ll S;
	scanf("%lld", &S);
	S--;
	ll T;
	scanf("%lld", &T);
	T--;

	vector<vector<ll>> graph(N, vector<ll>(0));

	for (ll i = 0; i < M; i++) {
		graph[v[i]].push_back(u[i]); //�t����
	}

	vector<int> flag(N, 0); //0x01:%3=1 0x02:%3=2 0x04:%3=0 ��OR
	queue<LLPair> q;
	q.push(LLPair(T, 0));

	while (q.empty() == false) {
		LLPair curr = q.front();
		q.pop();
		ll currDist = curr.dist;
		ll nextDist = curr.dist + 1;

		for (auto next : graph[curr.node]) {
			if ((flag[next] & 0x04) > 0 && (nextDist % 3) == 0) {
				continue;
			}

			if ((flag[next] & 0x02) > 0 && (nextDist % 3) == 2) {
				continue;
			}

			if ((flag[next] & 0x01) > 0 && (nextDist % 3) == 1) {
				continue;
			}

			if ((nextDist % 3) == 0) {
				flag[next] |= 0x04;

				if (next == S) {
					printf("%lld\n", nextDist / 3);
					return 0;
				}
			}
			else if ((nextDist % 3) == 2) {
				flag[next] |= 0x02;
			}
			else if ((nextDist % 3) == 1) {
				flag[next] |= 0x01;
			}

			q.push(LLPair(next, nextDist));
		}
	}

	printf("-1\n");
	return 0;
}
*/

//129 Sum Equals Xor
/*
int main() {
	char s[101010];
	scanf("%s", s);
	ll len = strlen(s);

	vector<ll> dp(2, 0);
	dp[0] = 1ll;
	dp[1] = 2ll;

	for (ll i = 1; i < len; i++) {
		if (s[i] == '1') {
			dp[0] *= 3ll;
			dp[0] %= MOD;
			dp[0] += dp[1];
			dp[0] %= MOD;
			dp[1] *= 2ll;
			dp[1] %= MOD;
		}
		else {
			dp[0] *= 3ll;
			dp[0] %= MOD;
		}
	}

	ll result = (dp[0] + dp[1]) % MOD;

	printf("%lld\n", result);
}
*/

//131 Friendships
/*
vector<vector<ll>> comb(ll n, ll r) {
	vector<vector<ll>> v(n + 1, vector<ll>(n + 1, 0));
	for (ll i = 0; i < v.size(); i++) {
		v[i][0] = 1;
		v[i][i] = 1;
	}
	for (ll j = 1; j < v.size(); j++) {
		for (ll k = 1; k < j; k++) {
			v[j][k] = (v[j - 1][k - 1] + v[j - 1][k]);
		}
	}
	return v;
}

struct LLPair {
	ll a = 0;
	ll b = 0;
	LLPair() {}
	LLPair(ll a, ll b) {
		this->a = a;
		this->b = b;
	}
};

// nCk�̑g�ݍ��킹�ɑ΂��ď��������s����
void recursive_comb(int *indexes, int s, int rest, std::function<void(int *)> f) {
	if (rest == 0) {
		f(indexes);
	}
	else {
		if (s < 0) return;
		recursive_comb(indexes, s - 1, rest, f);
		indexes[rest - 1] = s;
		recursive_comb(indexes, s - 1, rest - 1, f);
	}
}
void foreach_comb(int n, int k, std::function<void(int *)> f) {
	int *indexes = new int[k];
	recursive_comb(indexes, n - 1, k, f);
	delete[] indexes;
}

ll disCount = 0;
vector<LLPair> result;

int main() {
	ll N;
	scanf("%lld", &N);
	ll K;
	scanf("%lld", &K);

	auto c = comb(N - 1, 2);
	ll max = c[N - 1][2];

	if (max < K) {
		printf("-1\n");
		return 0;
	}

	disCount = max - K;

	for (ll i = 1; i <= N - 1; i++) {
		result.push_back(LLPair(i, N));
	}

	//���s��
	foreach_comb(N - 1, 2, [](int *indexes) {
		//std::cout << indexes[0] << ',' << indexes[1] << ',' << std::endl;
		if (disCount > 0) {
			result.push_back(LLPair(indexes[0] + 1, indexes[1] + 1));
			disCount--;
		}
	});

	printf("%lld\n", (ll)result.size());
	for (auto val : result) {
		printf("%lld %lld\n", val.a, val.b);
	}
}
*/

//133 Virus Tree 2
/*
int main() {
	ll N;
	scanf("%lld", &N);
	ll K;
	scanf("%lld", &K);
	vector<vector<ll>> tree(N, vector<ll>(0));
	for (ll i = 0; i < N - 1; i++) {
		ll a;
		scanf("%lld", &a);
		ll b;
		scanf("%lld", &b);
		tree[a - 1].push_back(b - 1);
		tree[b - 1].push_back(a - 1);
	}

	vector<ll> depth(N, -1);
	queue<ll> q;
	q.push(0);
	depth[0] = 0;
	ll result = K;

	while (q.empty() == false) {
		ll node = q.front();
		q.pop();
		ll d = depth[node];
		ll colorLast = d == 0 ? K - 1 : K - 2;

		for (auto next : tree[node]) {
			if (depth[next] >= 0) {
				//parent
				continue;
			}

			if (colorLast == 0) {
				printf("0\n");
				return 0;
			}

			depth[next] = d + 1;
			q.push(next);

			result *= colorLast;
			result %= MOD;
			colorLast--;
		}
	}

	printf("%lld\n", result);
}
/**/

//141 Who Says a Pun?
/*
vector<int> Zalgorithm(const char *s) {
	int len = strlen(s);
	vector<int> prefix(len);
	for (int i = 1, j = 0; i < len; i++) {
		if (i + prefix[i - j] < j + prefix[j]) {
			prefix[i] = prefix[i - j];
		}
		else {
			int k = max(0, j + prefix[j] - i);
			while (i + k < len && s[k] == s[i + k]) ++k;
			prefix[i] = k;
			j = i;
		}
	}
	prefix[0] = len;
	return prefix;
}

int main() {
	int N;
	scanf("%d", &N);
	char s[101010];
	scanf("%s", s);

	int result = 0;

	for (int i = 0; i < N - 1; i++) {
		auto prefix = Zalgorithm(s + i);

		int len = N - i;
		for (int j = 1; j < prefix.size(); j++) {
			result = max(result, min(prefix[j], j));
		}
	}

	printf("%d\n", result);
}
*/

//139 League
/*
struct LLPair {
	int a = 0;
	int b = 0;
	LLPair() {}
	LLPair(int a, int b) {
		this->a = a;
		this->b = b;
	}
};

int main() {
	int N;
	scanf("%d", &N);
	vector<vector<int>> A(N, vector<int>(N - 1, 0));
	for (int j = 0; j < N; j++) {
		for (int i = 0; i < N - 1; i++) {
			scanf("%d", &A[j][i]);
			A[j][i]--;
		}
	}

	vector<vector<vector<LLPair>>> graph(N, vector<vector<LLPair>>(N, vector<LLPair>(0)));
	vector<vector<vector<LLPair>>> graphR(N, vector<vector<LLPair>>(N, vector<LLPair>(0)));
	vector<vector<int>> inEdge(N, vector<int>(N, 0));
	for (int j = 0; j < N; j++) {
		for (int i = 0; i < N - 2; i++) {
			int a = j;
			int b = A[j][i];
			if (a > b) {
				swap(a, b);
			}

			int c = j;
			int d = A[j][i + 1];
			if (c > d) {
				swap(c, d);
			}

			graph[a][b].push_back(LLPair(c, d)); //a vs b �̌�� c vs d ���s��			
			graphR[c][d].push_back(LLPair(a, b)); //c vs d ���s���O�� a vs b
			inEdge[c][d]++; //c vs d �ւ̗����G�b�W��
		}
	}

	//���[�v�̌��o���g�|���W�J���\�[�g�Ŏ��{

	queue<LLPair> S; //���������N����0�ł���m�[�h�̃Z�b�g
	vector<LLPair> L; //�g�|���W�J���\�[�g�̌���
	
	for (int j = 0; j < N; j++) {
		for (int i = j + 1; i < N; i++) {
			if (graphR[j][i].size() == 0) {
				S.push(LLPair(j, i));
			}
		}
	}

	while (S.empty() == false) {
		LLPair node = S.front();
		S.pop();
		L.push_back(node);

		for (auto next : graph[node.a][node.b]) {
			inEdge[next.a][next.b]--;
			if (inEdge[next.a][next.b] == 0) {
				S.push(LLPair(next.a, next.b));
			}
		}
	}

	//���[�v�����݂���ꍇ�͉��Ȃ�
	if ((int)L.size() < N * (N - 1) / 2) {
		printf("-1\n");
		return 0;
	}

	int result = 0;
	stack<LLPair> st;
	vector<vector<int>> dist(N, vector<int>(N, 1));

	int maxDist = 0;

	for (auto node : L) {
		int d = dist[node.a][node.b];

		for (auto next : graph[node.a][node.b]) {
			if (d + 1 > dist[next.a][next.b]) {
				dist[next.a][next.b] = d + 1;
				maxDist = max(maxDist, d + 1);
			}
		}
	}

	result = maxDist;

	printf("%d\n", result);
}
*/
