#include <bits/stdc++.h>
using namespace std;
using ll  = long long;
using vl  = vector<ll>;
using vvl = vector<vl>;

#define rep(i,n) for(int i = 0; i < (n); ++i)
#define per(i,n) for(int i = (n)-1; i >= 0; --i)
#define rng(i,a,b) for(int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

int main() {
    int N;
    cin >> N;
    int cls[10] = {1,1,0,2,0,0,1,0,1,0};
    string ans[3] = {"hon", "pon", "bon"};
    cout << ans[cls[N % 10]] << endl;
    return 0;
}
