#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
int n;
ll m;
int d[10000], p[10000];
int main() {
    while(scanf("%d%lld",&n,&m)&&(n!=0||m!=0)) {
        for (int i=0; i<n; i++) scanf("%d%d",&d[i],&p[i]);
        vector<P> v;
        for (int i=0; i<n; i++) v.push_back(P(p[i], d[i]));
        sort(v.rbegin(), v.rend());
        int res = 0;
        for (int i=0; i<n; i++) {
            if (v[i].second <= m) m -= v[i].second;
            else {
                res += (v[i].second - m) * v[i].first;
                m = 0;
            }
        }
        printf("%d\n",res);
    }
}