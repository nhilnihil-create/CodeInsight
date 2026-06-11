#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> P;

ll N;

ll solve(vector<ll> A, vector<bool> B) {
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        if (i > 0) {
            if (A.at(i-1) == A.at(i)) {
                B.at(A.at(i)) = false;
                continue;
            }
        }
        for (ll j=2; A.at(i)*j <= A.at(N-1); j++) B.at(A.at(i)*j) = false;
        /*if (A.at(i)*2 <= A.at(N-1) && B.at(A.at(i)*2)){
            for (ll j=2; A.at(i)*j <= A.at(N-1); j++) B.at(A.at(i)*j) = false;
        }*/
    }
    for (int i = 0; i < N; i++) {
        if (B.at(A.at(i))) ans++;
    }
    return ans;
}

int main(){
    cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A.at(i);
    sort(A.begin(), A.end());
    vector<bool> B(A.at(N-1)+1, true);
    cout << solve(A,B) << endl;
    return 0;
}
