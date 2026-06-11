#include <bits/stdc++.h>
using namespace std;
using ll  = long long;
using vl  = vector<ll>;
using vvl = vector<vl>;

#define rep(i,n) for(int i = 0; i < (n); ++i)
#define per(i,n) for(int i = (n)-1; i >= 0; --i)
#define rng(i,a,b) for(int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

int main() {
    string s;
    cin >> s;
    string S[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    rep(i,7) {
        if (s != S[i]) continue;
        cout << 7-i << endl;
    }
    return 0;
}
