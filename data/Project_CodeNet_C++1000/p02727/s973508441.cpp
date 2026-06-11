#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;
    vector<int> p(a), q(b), r(c);
    for(int i = 0; i < a; i++) cin >> p[i];
    for(int i = 0; i < b; i++) cin >> q[i];
    for(int i = 0; i < c; i++) cin >> r[i];
    sort(p.begin(), p.end());
    sort(q.begin(), q.end());

    vector<int> apples(x+y+c);
    for(int i = 0; i < x; i++) apples[i] = p[a-i-1];
    for(int i = 0; i < y; i++) apples[i+x] = q[b-i-1];
    for(int i = 0; i < c; i++) apples[i+x+y] = r[i];

    sort(apples.begin(), apples.end());
    long long int ans = 0;
    for(int i = 1; i <= x+y; i++) ans += apples[x+y+c-i];
    cout << ans << endl;
    return 0;
}