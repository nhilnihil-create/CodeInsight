#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define int long long

int N, K, C;
string S;
int L[200100], R[200100];

signed main() {
    cin.tie(0); ios::sync_with_stdio(false);
    cin >> N >> K >> C >> S;
    int now = 0;
    rep(i, K) {
        while (S[now]=='x') now++;
        L[i] = now;
        now += C+1;
    }
    now = N-1;
    for (int i=K-1; i>=0; i--) {
        while (S[now]=='x') now--;
        R[i] = now;
        now -= C+1;
    }
    rep(i, K) if (L[i]==R[i]) cout << L[i]+1 << endl;
}