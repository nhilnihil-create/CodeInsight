#include "bits/stdc++.h"
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define rrep(i,n) for( int i = n; i >= 0; i-- )
#define REP(i,s,t) for( int i = s; i <= t; i++ )
#define RREP(i,s,t) for( int i = s; i >= t; i-- )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 2000000000
#define mod 1000000007
#define INF2 1000000000000000000

void solve(vector<int>& v1){
    vector<int> v2;
    while(v1.size() > 1) {
        rep(i, v1.size() - 1) {
            v2.push_back(abs(v1[i] - v1[i + 1]));
        }
        swap(v1, v2);
        v2.clear();   
    }
    cout << v1[0] << endl;
}

int count_two(int n) {
    int ret = 0;
    while(n > 0) {
        ret += n / 2;
        n /= 2;
    }
    return ret;
}

bool isadd(int r, int c) {
    if(count_two(r) - count_two(r - c) > count_two(c)) return false;
    else return true;
    
}
int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    string S;
    cin >> S;

    vector<int> v1, v2;
    if (N <= 12) {
        rep(i, N - 1) {
            v1.push_back(abs(S[i] - S[i + 1]));
        }
        solve(v1);
        return 0;
    }
    bool isall2 = false;
    rep(i, N) {
        if (S[i] == '1') continue;
        if (S[i] == '3') isall2 = true;
        if (S[i] == '2') {
            isall2 = false;
            break;
        }
    }
    rep(i, N) {
        if(isall2 && S[i] == '3') S[i] = '2';  
    }
    rep(i, N - 1) {
        v1.push_back(abs(S[i] - S[i + 1]));
    }
    int ans = 0;
    rep(i, v1.size()) {
        ans = (ans + isadd(v1.size() - 1, i) * v1[i]) % 2;
        //cout << v1.size() - 1 << " " << i << " " << isadd(v1.size() - 1, i) << endl;
    }
    // rep(i, v1.size()) cout << v1[i];
    // cout << endl;
    cout << ans * (isall2 + 1) << endl;


    return 0;
}
