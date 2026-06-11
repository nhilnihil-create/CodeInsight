#include <bits/stdc++.h>
using namespace std;
 
int N, M;
int WA[105000];
bool AC[105000];
 
void solve() {
    cin >> N >> M;
    int WAnum = 0;
    int ACnum = 0;
    for(int i = 1; i <= N; i++) {
        WA[i] = 0;
        AC[i] = false;
    }
    while(M--) {
        int p;
        string S;
        cin >> p >> S;
        if(AC[p]) continue;
        if(S == "AC") {
            AC[p] = true;
            ACnum++;
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