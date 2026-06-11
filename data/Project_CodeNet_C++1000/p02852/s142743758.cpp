#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

//const ll mod = 1000000007;
const ll INF = 1e9;
int N, M;
string S;

void solve() {
    //cout.precision(10);
    cin >> N >> M >> S;
    vector<int> dist(N + 1, INF);
    vector<int> MostLeft(N + 1, INF);
    dist[N] = 0;
    MostLeft[0] = N;
    int Next = N-1;
    int Left = N;
    int timer = 0;
    while(true) {
        timer++;
        int newLeft = Left;
        while(Next >= Left - M && Next >= 0) {
            if(S[Next] == '0') {
                dist[Next] = timer;
                newLeft = Next;
            }
            Next--;
        }
        if(newLeft == Left) {
            cout << -1 << endl;
            return;
        }
        Left = newLeft;
        MostLeft[timer] = Left;
        if(Next < 0) break;
    }
    timer = dist[0];
    for(int i = 0; i <= N; i++) {
        cerr << dist[i] << endl;
    }
    vector<int> ans;
    int now = 0;
    while(timer >= 1) {
        timer--;
        ans.push_back(MostLeft[timer] - now);
        now = MostLeft[timer];
    }
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i];
        if(i + 1 != ans.size()) cout << " ";
    }
    cout << endl;
    return;
}

int main() {
    solve();
    return 0;
}
