#include <bits/stdc++.h>
using namespace std;
#define All(A) A.begin(), A.end()
typedef pair<long long, long long> P;
int main(){
    long long N, D, A;
    cin >> N >> D >> A;
    vector<P> X(N);
    vector<long long> x(N);
    for(int i = 0; i < N; i++) {
        long long s, t;
        cin >> s >> t;
        X[i] = P(s, t);
        x[i] = s;
    }
    sort(X.begin(), X.end());
    sort(All(x));
    vector<long long> count(N + 1, 0);
    long long ans = 0;
    for(int i = 0; i < N; i++){
        if(i >= 1) count[i] += count[i - 1];
        if(X[i].second <= count[i]*A) continue;
        else X[i].second -= count[i]*A;
        int t = upper_bound(All(x), x[i] + 2 * D) - x.begin();
        long long s = (X[i].second + A - 1) / A;
        ans += s;
        count[i] += s;
        count[t] -= s;
    }
    cout << ans << endl;
}