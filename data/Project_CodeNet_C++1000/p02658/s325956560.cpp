#include <bits/stdc++.h>
using namespace std;
#define ALL(a) (a).begin(),(a).end()
#define rALL(a) (a).rbegin(),(a).rend()
typedef pair<int, int> Pint;
typedef pair<int64_t, int64_t> Pll;
typedef int64_t ll;

int main() {
    ll N, ans = 1;
    cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; i++){
        cin >> A.at(i);
        if (A.at(i) == 0){
            cout << 0 << endl;
            return 0;
        }
    }
    for (int i = 0; i < N; i++){
        if (1000000000000000000 / ans < A.at(i)){
            cout << -1 << endl;
            return 0;
        }
        else {
            ans *= A.at(i);
        }
        if (ans == 0){
            cout << 0 << endl;
            return 0;
        }
    }
    cout << ans << endl;

}