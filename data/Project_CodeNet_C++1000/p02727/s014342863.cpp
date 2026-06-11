#include <bits/stdc++.h>

#define F first
#define S second
#define int long long
#define inf 1000000000

using namespace std;

signed main(){
    int x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;
    vector<int> p(a), q(b), r(c);
    for (int i = 0; i < a; i++){
        cin >> p[i];
    }
    for (int i = 0; i < b; i++){
        cin >> q[i];
    }
    for (int i = 0; i < c; i++){
        cin >> r[i];
    }
    int ri = a-x, gi = b-y;
    sort(p.begin(), p.end());
    sort(q.begin(), q.end());
    sort(r.begin(), r.end());
    int sum = 0;
    vector<int> res(0);
    for (int i = ri; i < a; i++){
        sum += p[i];
        res.push_back(p[i]);
    }
    for (int i = gi; i < b; i++){
        sum += q[i];
        res.push_back(q[i]);
    }
    sort(res.begin(), res.end());
    int ci = c-1, resi = 0;
    while (ci >= 0 && r[ci] > res[resi]){
        sum -= res[resi];
        sum += r[ci];
        ci--; resi++;
    }
    cout << sum << endl;
    return 0;
}





















