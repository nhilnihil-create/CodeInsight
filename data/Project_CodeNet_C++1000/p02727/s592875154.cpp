#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    int X, Y, A, B, C; cin >> X >> Y >> A >> B >> C;
    vector<int> p(A), q(B), r(C);
    rep(i, A){
        cin >> p[i];
    }
    rep(i, B){
        cin >> q[i];
    }
    rep(i, C){
        cin >> r[i];
    }
    sort(p.begin(), p.end());
    sort(q.begin(), q.end());
    sort(r.begin(), r.end());

    int cntA = 0;
    int cntB = 0;
    int total = 0;

    int pnum = A-1;
    int qnum = B-1;
    int rnum = C-1;

    ll ans = 0;
    while(total < X+Y){
        int pnow = 0;
        if(pnum != -1){
            pnow = p[pnum];
        }
        int qnow = 0;
        if(qnum != -1){
            qnow = q[qnum];
        }
        int rnow = 0;
        if(rnum != -1){
            rnow = r[rnum];
        }
        if(cntA == X)pnow = 0;
        if(cntB == Y)qnow = 0;
        if(rnow >= pnow && rnow >= qnow){
            total++;
            ans += rnow;
            rnum--;
        } else if(pnow > qnow){
            total++;
            cntA++;
            ans += pnow;
            pnum--;
        } else {
            total++;
            cntB++;
            ans += qnow;
            qnum--;
        }
    }

    cout << ans << endl;

    return 0;
}