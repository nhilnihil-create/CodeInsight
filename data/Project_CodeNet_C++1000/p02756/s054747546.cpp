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



  








      

 
int main() {
    string S;
    cin >> S;
    deque<char> dS(S.size());
    for (int i = 0; i < S.size(); ++i) dS[i] = S[i];

    int Q; cin >> Q;
    int rev = 0;
    for (int i = 0; i < Q; ++i) {
        int type; cin >> type;
        if (type == 2) {
            int f; char c;
            cin >> f >> c; --f;
            if (rev) f = 1 - f; // 反転状態だったら、フラグを反転
            if (f == 0) dS.push_front(c);
            else dS.push_back(c);
        }
        else rev = 1 - rev;
    }
    if (rev) reverse(dS.begin(), dS.end());
    for (auto c : dS) cout << c;
    cout << endl;
}