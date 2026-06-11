#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {

    int K , N;
    cin >> K >> N;
    vector<int> a(N);
    rep(i,N) cin >> a[i];
    a.push_back(a[0] + K);
    int l = 0;
    for(int i = 0; i < N; i++){
        l = max(l, a[i+1] - a[i] );
    }
    cout << K - l << endl;

    return 0;
}