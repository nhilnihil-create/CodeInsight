#include <iostream>
#include <algorithm>
#define REP(i,n) for(int i=0;i<n;i++)
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int d[m];
    REP(i,m)
        cin >> d[i];
    int cnt[n];
    REP(i,n)
        cnt[i] = n+1;
    REP(i,n)
    REP(j,m) {
        if(d[j] == i+1)
            cnt[i] = 1;
        else if(i-d[j] >= 0)
            cnt[i] = min(cnt[i],cnt[i-d[j]]+1);
    }
    cout << cnt[n-1] << '\n';
}