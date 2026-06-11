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

int N;

int main() {
    cin >> N;
    vector<int> a(N + 1, 0);
    rep(i,N) cin>>a[i+1];
    vector<int> boxes(N+1,0);
    for(int i = N; i>0; --i) {
        int count = 0;
        for(int j = i + i; j <= N; j += i) {
            if (boxes[j]) count++;
        }
        if (count%2 != a[i]) boxes[i] = 1;
    }
    vector<int> res;
    for (int i = 1; i <= N; ++i) {
        if (boxes[i]) res.push_back(i);
    }
    int M = res.size();
    cout << M << endl;
    rep(i,M) cout << res[i] << " ";
    cout << endl;
}