#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, n) for(int i = 0; i < (n); ++i)
#define REPr(i, n) for(int i = (n)-1; i >= 0; --i)
#define FORq(i, m, n) for(int i = (m); i <= (n); ++i)
#define FORqr(i, m, n) for(int i = (n); i >= (m); --i)
#define MP make_pair
#define SIN(x, S) (S.count(x) != 0)
#define M0(x) memset(x, 0, sizeof(x))
#define FILL(x, y) memset(x, y, sizeof(x))
#define MM(x) memset(x, -1, sizeof(x))
#define ALL(x) (x).begin(), (x).end()
#define DB(x) cerr << #x << " = " << x << endl
#define DB2(x, y)                                                              \
    cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n";
#define DEBUG                                                                  \
    int x12345;                                                                \
    cin >> x12345;
typedef pair<int, int> PII;
typedef pair<long long, long long> PLL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<long long> VL;
typedef long long ll;
typedef long long integer;
///////////////////////////////////////////////
const long long MOD = 1e9 + 7;
template <class T> inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

template <class T> inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

///////////////////////////////////////////////
/// 🍈( '-' 🍈 |AC|
ll N,M,V,P;
vector<ll> A;

bool judge(ll key){
    ll L = key;
    ll K = A[key];
    if (K + M < A[N-P]) return false;
    if (key >= N - P) return true;
    ll canvote = M*L+(P-1)*M;
    ll limit = K + M;
    for (size_t i = key + 1; i <= N - P ; i++) {
        canvote += min(limit - A[i],M);
    }

    return canvote >= M * (V-1);

}

int binary_search(){
	// lower_bound (a-1,b] (ans = [a,b])
	// <= left never satisfy
	// right <= always satisfy

	int left = -1; 
	int right = N; // index of size + 1;

	while(right - left > 1){
			int mid = left + (right - left) / 2;

			if (judge(mid)) right = mid;
			else left = mid;
	}

	// left is the maximum that don't satisfy the condition.
	// right is the minimum that satisfies the condtion.
	
	return right; 

}

int main() {
    cin >> N >> M >> V >> P;
    REP(i,N){
        ll a; cin >> a;
        A.push_back(a);
    }

    sort(ALL(A));

    cout << N - binary_search() << endl;
}