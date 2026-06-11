#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    int N; cin >> N;
    vector<int> D(N);
    rep(i, N){
        cin >> D[i];
    }

    sort(D.begin(), D.end());
    int x = N/2;
    int ans = D[x] - D[x-1];

    cout << ans << endl;


    return 0;
}