#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    long long x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;

    vector<long long> p(a);
    vector<long long> q(b);
    vector<long long> r(c);

    for(long long i = 0; i < a; i++) cin >> p[i];
    for(long long i = 0; i < b; i++) cin >> q[i];
    for(long long i = 0; i < c; i++) cin >> r[i];

    sort(p.begin(), p.end(), greater<long long>());
    sort(q.begin(), q.end(), greater<long long>());

    vector<long long> eat;

    for(long long i = 0; i < x; i++) eat.push_back(p[i]);
    for(long long i = 0; i < y; i++) eat.push_back(q[i]);
    for(long long i = 0; i < c; i++) eat.push_back(r[i]);

    sort(eat.begin(), eat.end(), greater<long long>());

    long long ans = 0;
    for(long long i = 0; i < x+y; i++) ans += eat[i];

    printf("%lld\n", ans);
    return 0;
}