#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

#define REPR(i,n) for(int i=(n); i >= 0; --i)
#define FOR(i, m, n) for(int i = (m); i < (n); ++i)
#define REP(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define ALL(a)  (a).begin(),(a).end()

template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
int gcd(int a,int b){return b?gcd(b,a%b):a;}
typedef long long ll;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}


int main() {
    int N;
    cin >> N;

    vector<pair<string,int>> v(N);
    // iまでのわ
    vector<int> rsum(N,0);

    REP(i,N) {
        string s;
        int t;
        cin >> s >> t;

        rsum[i] = t;
        if ( i > 0) rsum[i] += rsum[i-1];

        v[i] = make_pair(s,t);
    }

    string X;
    cin >> X;

    // find
    REP(i,N) {
        if (v[i].first == X) {
            cout << rsum[N-1]-rsum[i] << endl;
            return 0;
        }
    }

    return 0;
}
