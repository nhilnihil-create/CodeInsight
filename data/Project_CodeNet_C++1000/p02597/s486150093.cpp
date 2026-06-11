#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<string> c(N);
    string S;
    cin >> S;
    for(int i=0;i<N;i++) {
        c[i] = S[i];
    }

    int WL = 0;
    int RL = 0;
    int WR = 0;
    int RR = 0;

    for(int i=0;i<N;i++) {
        if (c[i] == "W") {
            WR++;
        } else {
            RR++;
        }
    }
    int score = 100000000;
    for(int sikiri = 0; sikiri <= N; sikiri++) {
        if(sikiri >= 1) {
            if (c[sikiri - 1] == "R") {
                RR--;
                RL++;
            } else {
                WR--;
                WL++;
            }
        }
        
        int AA = WL;
        int BB = RR;
        int C = AA;
        if (C < BB) {
            C = BB;
        }
        //cout << "sikiri:" << sikiri << " R:" << RR << " W:" << WR << " C:" << C << endl;
        if (score >= C) {
            score = C;
        }
    }
    cout << score << endl;
}