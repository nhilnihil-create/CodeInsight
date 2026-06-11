#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i, n) FOR(i,0,n)
#define RREP(i,a,b) for(int i=(a);i>=(b);i--)
//区間数え上げの問題
//https://www.hamayanhamayan.com/entry/2020/04/26/232032
// iを固定してjを回す
// S[i] = S[j+1]
int main(void){
    string S;
    cin >> S;
    int N = S.length();
    ll ans = 0;
    vector<ll> cnt(2020); // mod 2019 であるjの数
    cnt[0] = 1;
    int total = 0;
    int p = 1;
    RREP(i,N-1,0){
        total = (total + (S[i] - '0') * p) % 2019;
        ans += cnt[total];
        p = (p * 10) % 2019;
        cnt[total]++;
    }
    cout << ans << endl;
    return 0;
}