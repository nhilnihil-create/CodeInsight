#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int  X,Y,A,B,C;
    cin >> X >> Y >> A >> B >> C;
    vector<int>p(A);
    vector<int>q(B);
    for(int i = 0; i < A; i++) {
        cin >> p[i];
    }
    for(int i = 0; i < B; i++) {
        cin >> q[i];
    }
    sort(p.begin(),p.end());
    sort(q.begin(),q.end());
    vector<int>cnt;
    for(int i = 0; i < X; i++) {
        cnt.push_back(p[A-i-1]);
    }
    for(int i = 0; i < Y; i++) {
        cnt.push_back(q[B-i-1]);
    }
    int ans = 0;
    for(int i = 0; i < C; i++) {
        int r;
        cin >> r; 
        cnt.push_back(r);
    }
    sort(cnt.begin(),cnt.end());
    for(int i = 0; i < X+Y; i++) {
        ans+=cnt[cnt.size()-1-i];
    }
    cout << ans << endl;
}