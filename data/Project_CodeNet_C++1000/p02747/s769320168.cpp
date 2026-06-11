#include <bits/stdc++.h>
using namespace std;

const long long INF = 1LL << 60;
int MOD = 1000000007;
int PI = 3.14159265358979323846;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

typedef long long ll;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<(int)(n);i++)
#define For(i,s,n) for (int i=s;i<(int)(n);i++)
#define vi vector<int>
#define vii vector< vector<int> >
#define All(c) (c).begin(), (c).end()
#define Print(x) cout<<(x)<<"\n"
#define Sort(v) sort(All(v))
#define Reverse(v) reverse(All(v))


//日立製作所 社会システム事業部 PC 2020 A

string S;

int main() {

	cin >> S;
	if (S.size() % 2) Print("No");
	else {
		bool flag = true;
		rep(i, S.size() / 2) {
			if (S[2 * i] != 'h' || S[2 * i + 1] != 'i') flag = false;
		}
		if (flag) Print("Yes");
		else Print("No");
	}
}
