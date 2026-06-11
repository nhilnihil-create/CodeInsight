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
    int N;
    string S;
    cin >> N >> S;
    for (char &c : S) {
        int a = (c - 'A');
        a = (a + N) % 26;
        c = 'A' + a;
    }
    cout << S << endl;
    return 0;
}
