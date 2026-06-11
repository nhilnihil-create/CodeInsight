#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    int x, y, a, b, c; cin >> x >> y >> a >> b >> c;
    vector<long long> p(a), q(b), r(c);
    for (int i = 0; i < a; i++) cin >> p[i]; sort(p.begin(), p.end()); reverse(p.begin(), p.end());
    for (int i = 0; i < b; i++) cin >> q[i]; sort(q.begin(), q.end()); reverse(q.begin(), q.end());
    for (int i = 0; i < c; i++) cin >> r[i]; sort(r.begin(), r.end()); reverse(r.begin(), r.end());

    vector<long long> s(x + y + c);
    for (int i = 0; i < x; i++) s[i] = p[i];
    for (int i = 0; i < y; i++) s[i + x] = q[i];
    for (int i = 0; i < c; i++) s[i + x + y] = r[i];
    sort(s.begin(), s.end()); reverse(s.begin(), s.end());

    long long ans = 0;
    for (int i = 0; i < x + y; i++) ans += s[i];
    cout << ans << endl;
}