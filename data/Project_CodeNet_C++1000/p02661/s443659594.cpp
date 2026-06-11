#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0);
#define FOR(i,s,n) for(int i = (s); i < (n); i++)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) for(int i = (n); i >= 0; i--)
#define ALL(n) (n).begin(), (n).end()
#define RALL(n) (n).rbegin(), (n).rend()
#define ATYN(n) cout << ( (n) ? "Yes":"No") << '\n';
#define CFYN(n) cout << ( (n) ? "YES":"NO") << '\n';
#define OUT(n) cout << (n) << '\n';
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

int main(void)
{
    IOS

    int N; cin >> N;
    vector<int> vl(N),vr(N);
    REP(i,N) {
        cin >> vl[i] >> vr[i];
    }

    sort(ALL(vl));
    sort(ALL(vr));
    int ans = 0;
    if (N % 2 == 0) {
        int l = vl[N/2-1] + vl[N/2];
        int r = vr[N/2-1] + vr[N/2];
        ans = r - l + 1;
    } else {
        int l = vl[N/2];
        int r = vr[N/2];
        ans = r - l + 1;
    }

    cout << ans << '\n';

    return 0;
}