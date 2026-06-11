#include <bits/stdc++.h>
using namespace std;
#define int long long
int s, t;
long long a[2], b[2];

bool inf() {
    long long dist1 = s*a[0] + t*a[1];
    long long dist2 = s*b[0] + t*b[1];
    return (dist1 == dist2);
}

bool f(long long time) {
    long long ta = (s*a[0]+t*a[1]), ao = (s*b[0]+t*b[1]);
    long long sta = ta * (time-1), sao = ao * (time-1);
    long long mta = sta + s * a[0], mao = sao + s * b[0];
    long long fta = ta * time, fao = ao * time;
    if (mta <= mao && fta >= fao) return true;
    if (mta >= mao && fta <= fao) return true;
    return false;
}

long long fin(long long time) {
    long long ta = (s*a[0]+t*a[1]), ao = (s*b[0]+t*b[1]);
    long long sta = ta * (time-1), sao = ao * (time-1);
    long long mta = sta + s * a[0], mao = sao + s * b[0];
    long long fta = ta * time, fao = ao * time;
    if (mta == mao) return 1LL;
    if (mta > mao && fta < fao) return 2LL;
    return 0LL;
}

signed main() {
    cin >> s >> t >> a[0] >> a[1] >> b[0] >> b[1];
    if (inf()) { printf("infinity\n"); return 0; }
    if (a[0]<b[0]&&a[1]<b[1]) { printf("0\n"); return 0; }
    if (a[0]>b[0]&&a[1]>b[1]) { printf("0\n"); return 0; }
    if (b[0] > a[0]) { swap(a[0], b[0]); swap(a[1], b[1]); }
    
    long long ok = 0, ng = 1e18;
    while (abs(ok-ng) > 1) {
        long long mid = (ok + ng) / 2;
        if (f(mid)) ok = mid;
        else ng = mid;
    }
    
    long long ans;
    if (ok == 1) ans = 1;
    else ans = (ok-2)*2 + 1 + fin(ok);
    ans = max(0LL, ans);
    cout << ans << endl;
    return 0;
}