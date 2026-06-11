#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    int N; cin >> N;
    vector<double> V(N);
    rep(i,N){
        cin >> V[i];
    }
    sort(V.begin(), V.end());

    double ans = (V[0]+V[1]) / 2.0;

    for (int i = 2; i < N; i++){
        ans += V[i];
        ans /= 2.0;
    }

    cout << ans << endl;


    return 0;
}