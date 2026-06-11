#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i < (int)(n); i++)
using ull = unsigned long long;
using ll = long long;


int main() {

    while (true) {
        int H;
        cin >> H;
        if (H==0) break;

        int P[H][5] = {};
        rep(i, H) rep(j, 5) cin >> P[i][j];

        int score = 0;
        bool can_vanish = true;

        while (can_vanish) {
            can_vanish = false;
            rep(i, H) {
                int p0 = P[i][0], p1 = P[i][1], p2 = P[i][2], p3 = P[i][3], p4 = P[i][4];

                if ((p0==p1) && (p1==p2) && (p2!=p3)) {
                    if (P[i][2] != 0) can_vanish = true;
                    score += P[i][2] * 3;
                    P[i][0] = P[i][1] = P[i][2] = 0;
                } else if ((p0!=p1) && (p1==p2) && (p2==p3) && (p3!=p4)) {
                    if (P[i][2] != 0) can_vanish = true;
                    score += P[i][2] * 3;
                    P[i][1] = P[i][2] = P[i][3] = 0;
                } else if ((p1!=p2) && (p2==p3) && (p3==p4)) {
                    if (P[i][2] != 0) can_vanish = true;
                    score += P[i][2] * 3;
                    P[i][2] = P[i][3] = P[i][4] = 0;
                } else if ((p0==p1) && (p1==p2) && (p2==p3) && (p3!=p4)) {
                    if (P[i][2] != 0) can_vanish = true;
                    score += P[i][2] * 4;
                    P[i][0] = P[i][1] = P[i][2] = P[i][3] = 0;
                } else if ((p0!=p1) && (p1==p2) && (p2==p3) && (p3==p4)) {
                    if (P[i][2] != 0) can_vanish = true;
                    score += P[i][2] * 4;
                    P[i][1] = P[i][2] = P[i][3] = P[i][4] = 0;
                } else if ((p0==p1) && (p1==p2) && (p2==p3) && (p3==p4)) {
                    if (P[i][2] != 0) can_vanish = true;
                    score += P[i][2] * 5;
                    P[i][0] = P[i][1] = P[i][2] = P[i][3] = P[i][4] = 0;
                }
            }

            rep(j, 5) {
                int i=H-1;
                while (i>0) {
                    int cnt = 0;
                    while ((P[i][j] == 0) && (cnt<=H)) {
                        for (int h=i; h>=1; h--) P[h][j] = P[h-1][j];
                        P[0][j] = 0;
                        cnt++;
                    } 
                    i--;
                }
            }
        }

        cout << score << endl;

    }

    return 0;
}


