#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(c) (c).begin(),(c).end()
#define RALL(c) (c).rbegin(),(c).rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)

const ll INF = 1e18 + 10;

int N, K;
string S;

int main() {
    cin >> N >> K >> S;
    int a = 0;
    rep(i,N-1) if (S[i] != S[i+1]) ++a;
    cout << N-1 - max(a-K*2,0) << endl;
}