#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)  FOR(i,0,n)
#define req(i,n) for(int i = 1;i <=n;i++)
#define pai 3.14159265358979323846
const int INF = 1001001001;
typedef long long ll;
int A[3][3], N;
bool punched[3][3];
bool ok[3][3];
using Graph = vector<vector<int>>;
vector<vector<int>> field;
vector<bool> seen;

const int MOD = 1000000007;
typedef pair<int,int> P;

//最大公約数
int gcd(int a,int b){
	if (a%b == 0){
		return b;
	}
	else{
		return gcd(b,a%b);
	}

}

//最小公倍数
int lcm(int a,int b){
	return a /gcd(a,b) * b;
}

//素数判定
bool is_prime(long long N) {
    if (N == 1) return false;
    for (long long i = 2; i * i <= N; ++i) {
        if (N % i == 0) return false;
    }
    return true;
}

// 素因数分解
vector<pair<long long, long long> > prime_factorize(long long n) {
    vector<pair<long long, long long> > res;
    for (long long p = 2; p * p <= n; ++p) {
        if (n % p != 0) continue;
        int num = 0;
        while (n % p == 0) { ++num; n /= p; }
        res.push_back(make_pair(p, num));
    }
    if (n != 1) res.push_back(make_pair(n, 1));
    return res;
}

// 10進数から2進数
int binary(int bina){
    int ans = 0;
    for (int i = 0; bina>0 ; i++)
    {
        ans = ans+(bina%2)*pow(10,i);
        bina = bina/2;
    }
    return ans;
}





int main() {
    int N; 
    long long K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i], --A[i];

    deque<int> a; // 繰り返しの部分
    vector<bool> seen(N, false); // 一度見たかどうか
    int cur = 0;
    while (true) {
        // 一度通った頂点を見つけたときの処理
        if (seen[cur]) {
            while (a[0] != cur) {
                // 最初の余計な数手分を除去する
                --K;
                a.pop_front();

                // 繰り返す前に K が限界になったらリターン
                if (K == 0) {
                    cout << a[0]+1 << endl;
                    return 0;
                }
            }
            break;
        }
        // 最初は愚直にシミュレーションしつつ、履歴をメモしていく
        a.push_back(cur);
        seen[cur] = true;
        cur = A[cur];
    }
    cout << a[K % a.size()]+1 << endl;
}
