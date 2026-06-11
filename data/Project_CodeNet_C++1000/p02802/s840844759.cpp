#include <bits/stdc++.h>
using namespace std;

int N, M;
std::vector<int> WA(105000,0);
std::vector<bool> AC(105000,false);

void solve() {
    cin >> N >> M;
    int WAnum = 0;
    int ACnum = 0;

    while(M--) {
        int p;
        string S;
        cin >> p >> S;
        if(AC[p]) continue;
        if(S == "AC") {
            AC[p] = true;
            ACnum++;
            // ACになるまでのWAなのでACに
            // ならなかった場合合計されない
            WAnum += WA[p];
        } else if(S == "WA") {
            WA[p]++;
        }
    }
    cout << ACnum << " " << WAnum << endl;
    return;
}

int main() {
    solve();
    return 0;
}
