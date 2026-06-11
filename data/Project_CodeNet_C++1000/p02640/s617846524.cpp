#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i,n) for (int i = 0; i < (n); ++i)

const string YES = "Yes";
const string NO = "No";

void solve(long long X, long long Y){
    string ans = NO;

    rep(i,200){
        rep(j,200){
            if(i + j != X) continue;
            if(2 * i + 4 * j != Y) continue;
            ans = YES;
        }
    }

    cout << ans << endl;

}

int main(){
    long long X;
    scanf("%lld",&X);
    long long Y;
    scanf("%lld",&Y);
    solve(X, Y);
    return 0;
}
