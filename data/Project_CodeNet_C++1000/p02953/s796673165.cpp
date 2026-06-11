#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    int N; cin >> N;
    vector<int> H(N);
    rep(i, N){
        cin >> H[i];
    }
    int now = 0;
    rep(i, N){
        if(now <= H[i]-1){
            H[i]--;
            now = H[i];
        } else if (H[i] != now) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;

    return 0;
}