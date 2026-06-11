#include <bits/stdc++.h>

using namespace std;
using ll =long long;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> PII;
#define SORT(a) sort((a).begin(),(a).end())
#define rSORT(a) reverse((a).begin(),(a).end())
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
#define debug(x)  cerr << #x << " = " << (x) << endl;
using P = pair<int,int>;
//Write FroM this Line

int main()
{
	int N, M;
	cin >> N >> M;
	vector<P> A(N);
	rep(i,N) cin >> A[i].first >> A[i].second;  // A[i] = {days, money};

	sort(A.begin(), A.end());

	int count = 0;
	priority_queue<int> que;
	ll ans = 0;
	for(int day = M - 1; day >= 0; day--){
		//day日目に受ける仕事を決める。
		// A[i].first が M - day となる仕事をqueに入れる。
		for(int i = count; i < N; i++){
			if(A[i].first == M - day){
				que.push(A[i].second);
			} else {
				count = i; 
				break;
			}
		}
		if(que.empty()) {
			// day 日に受けれる仕事は無い
			continue;
		} else {
			int kane = que.top(); que.pop();
			ans += kane;
		}
	}
	cout << ans << endl;
}
