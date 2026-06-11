#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int main(){
    int n; cin >> n;
    string s; cin >> s;

    // int c = 1;
    // string S = "1000";
    // if(S[0] == ('0' + c)) cout << "yes" << endl;
    // else cout << "no" << endl;

    int cnt = 0;
    rep (i, 1000){
        int c[3] = {i / 100, (i / 10) % 10, i % 10};
        int f = 0;

        // cout << c[0] << c[1] << c[2] << endl;

        rep (j, n){
            if (s[j] == ('0' + c[f])) f++;
            if (f == 3) break;
        }
        if (f == 3) cnt++;
    }
    cout << cnt << endl;
}

// int N;
// string S;
// int cnt;

// int main() {
//     int N; cin >> N;
//     string S; cin >> S;
//     int cnt;

// 	// cin >> N >> S;
// 	for (int i = 0; i < 1000; i++) {
// 		int c[3] = {i / 100, (i / 10) % 10, i % 10};
// 		int f = 0;
// 		for (int j = 0; j < N; j++) {
// 			if (S[j] == ('0' + c[f])) f++;
// 			if (f == 3) break;
// 		}
// 		if (f == 3) cnt++;
// 	}
// 	cout << cnt << endl;
// 	return 0;
// }