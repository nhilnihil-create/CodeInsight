#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define reps(i,s,n) for (int i = (s); i <= (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    
    int N;
    cin >> N;
    vector<int> H(N);
    for(int i = 0; i < N; i++){
        cin >> H[i];
    }
    reverse(H.begin(), H.end());

    int ans = 0;
    int val = 0;

    for(int i = 1; i < N; i++){
        if(H[i-1] <= H[i]){
            val++;
        } else {
            val = 0;
        }
        ans = max(ans, val);
    }
    cout << ans << endl;

    return 0;
}
    