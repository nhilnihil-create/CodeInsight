#include<bits/stdc++.h>
#define REP(i, n) for(int i=0; i<n; i++)
#define COUT(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << endl
using namespace std;
using ll = long long;
using Graph = vector<vector<ll>>;

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

int main() {
    int N;
    cin >> N;
    int X[N];
    for (int i = 0; i < N; i++)
    {
        cin >> X[i];
    }
    sort(X, X+N);
    int ans = 100000000;
    for (int i = 0; i < 100; i++)
    {
        int total = 0;
        for (int j = 0; j < N; j++)
        {
            total +=(X[j]-i)*(X[j]-i);
        }
        chmin(ans, total);
    }
    cout << ans << endl;
    
}