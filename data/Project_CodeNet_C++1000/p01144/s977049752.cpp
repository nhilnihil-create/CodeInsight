#include "bits/stdc++.h"
#define pb push_back
#define all(a) (a).begin(),(a).end()
#define rep(i, n) for(int i=0;i<(n);++i)
#define debug(x) cout << #x << " : " << x << " ------------"
using namespace std;
using Info = tuple<int, int>;
int main()
{
    int n, m;
    while (cin >> n >> m, n | m) {
        vector<Info> sections;
        int ev = 0;
        rep (i, n) {
            int d, p;
            cin >> d >> p;
            sections.pb(Info(p, d));
            ev += d * p;
        }
        sort(all(sections), greater<Info>());
        for (auto s : sections) {
            int d = get<1>(s), p = get<0>(s);
            ev -= min(m, d) * p;
            m -= d;
            
            if (m <= 0) break;
            else if (ev < 0) {
                ev = 0;
                break;
            }
        }
        cout << ev << endl;
    }
    return EXIT_SUCCESS;
}