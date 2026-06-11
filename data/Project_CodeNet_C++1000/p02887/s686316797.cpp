#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

//#include "atcoder/all"
//using namespace atcoder;

vector<int> parse(int n, string& s) {
    char c = s[0];
    int tmp = 1;
    vector<int> res;
    for (int i = 1; i < n; i++) {
        if (s[i] != c) {
            c = s[i];
            res.push_back(tmp);
            tmp = 1;
        } else {
            tmp++;
        }
    }
    res.push_back(tmp);
    return res;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	string s;
	cin >> n >> s;
	cout << parse(n, s).size() << endl;
	return 0;
}
