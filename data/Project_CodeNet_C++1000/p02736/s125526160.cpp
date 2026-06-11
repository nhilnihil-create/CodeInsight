#include <bits/stdc++.h>
////////////////////////////////////////////////////////////
#define all(x) (x).begin(), (x).end() 
const int inf = 1e9;
const long long INF=1e15;
#define endl '\n'
#define rep(i, n) for(int i=0;i<(n);++i)
#define repp(i, a, b) for(int i=(a);i<=(b);++i)
#define pb push_back
#define eb emplace_back
#define fastio ios::sync_with_stdio(false);cin.tie(0); //cout.tie(0);

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll,ll> llll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;

int x[3][3] = {
	0,1,2,
	1,0,1,
	2,1,0
};

int solve() {
	int n; cin >> n;
	string a; cin >> a;
	// ai = 1, 2, 3 -> 0 1 2
	// |ai-ai+1| = 0, 1, 2
	// |ai-ai+1| = 0, 1, 2 ....
	//   0 1 2
	// 0 0 1 2 -> 0 1 0
	// 1 1 0 1 -> 1 0 1
	// 2 2 1 0 -> 0 1 0
	
	// example
	// 0 1 2 0
	//  1 1 2
	//   0 1
	//    1
	// 1. a#b = b#a
	// 2. (a#b)#c = a#(b#c)  (I proved it)
	//     no! 1#1#2, 2#1#1 is exception. (2 or 0)
	
	// a b 11
	// ab
	
	// a b c 1 2 1
	// ab bc
	// ac
	
	// a b c d 1 3 3 1
	// ab bc cd
	// ac bd
	// abcd
	
	// a b c d e 1 4 6 4 1
	// ab bc cd de
	// ac bd ce
	// abcd bcde
	// ae
	
	// a b c d e f 1 5 10 10 5 1
	// a#b b#c c#d d#e e#f
	// a#c b#d c#e d#f
	// abcd bcde cdef
	// ae bf
	// abef
	
	// a b c d e f g 1 6 15 20 15 6 1
	// ab bc cd de ef fg
	// ac bd ce df eg
	// abcd bcde cdef defg
	// ae bf cg
	// aebf bfcg
	// aceg
	
	// a b c d e f g h 1 7 21 35 35 21 7 1
	// ab bc cd de ef fg gh
	// ac bd ce df eg fh
	// abcd bcde cdef defg efgh
	// ae bf cg dh
	// aebf bfcg cgdh
	// aecg bfdh
	// abcdefgh
	
	// a b c d e f g h i
	// ab bc cd de ef fg gh hi
	// ac bd ce df eg fh gi
	// abcd bcde cdef defg efgh fhgi
	// ae bf cg dh ei
	// aebf bfcg cgdh dhei
	// aecg bfdh cgei
	// abcdefgh bcdefghi
	// ai
	
	// a b c d e f g h i j
	// ab bc cd de ef fg gh hi ij
	// ac bd ce df eg fh gi hj
	// abcd bcde cdef defg efgh fhgi gihj
	// ae bf cg dh ei fj
	// aebf bfcg cgdh dhei eifj
	// aecg bfdh cgei dhfj
	// abcdefgh bcdefghi cdefghij
	// ai bj
	// abij
	
	// a b c d e f g h i j k
	// ab bc cd de ef fg gh hi ij jk
	// ac bd ce df eg fh gi hj ik
	// abcd bcde cdef defg efgh fhgi gihj hjik
	// ae bf cg dh ei fj gk
	// aebf bfcg cgdh dhei eifj fjgk
	// aecg bfdh cgei dhfj eigk
	// abcdefgh bcdefghi cdefghij defghijk
	// ai bj ck
	// aibj bjck
	// aick
	
	// a b c d e f g h i j k l
	// ab bc cd de ef fg gh hi ij jk kl
	// ac bd ce df eg fh gi hj ik jl
	// abcd bcde cdef defg efgh fhgi gihj hjik ikjl
	// ae bf cg dh ei fj gk hl
	// aebf bfcg cgdh dhei eifj fjgk gkhl
	// aecg bfdh cgei dhfj eigk fjhl
	// abcdefgh bcdefghi cdefghij defghijk efghijkl
	// ai bj ck dl
	// aibj bjck ckdl
	// aick bjdl
	// abcdijkl
	// gotcha parity of nCi !
	bool isone = false;
	rep(i, n) if(a[i] == '2') isone = true;
	vi parity(n);
	parity[0] = 0;
	for(int i=1;i<n;i++) {
		parity[i] = parity[i-1] + __builtin_ctz(n-i) - __builtin_ctz(i);
	}
	int ans = 0;
	rep(i, n) if(parity[i] == 0) ans = x[ans][a[i]-'1'];
	if(ans == 1) {
		cout << ans;
	} else {
		if(isone) {
			cout << 0;
			return 0;
		}
		cout << ans;
	}
}

int main() {
	fastio;
	solve();
}

