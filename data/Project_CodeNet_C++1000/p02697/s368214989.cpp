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
    int N, M;
    cin >> N >> M;
    int m = 0;
    int l1 = 1, r1 = N/2, l2 = N/2+1, r2 = N;
    if (N % 2 ==0) r1--;
    while(m < M) {
        if (m % 2 == 0) {
            cout << l2 << " " << r2 << endl;
            l2++;
            r2--;
        } else {
            cout << l1 << " " << r1 << endl;
            l1++;
            r1--;
        }
        m++;
    }

    return 0;
}