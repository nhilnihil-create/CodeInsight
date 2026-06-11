#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int N, M, p;
    cin >> N >> M;
    string S;
    map<int, int> mpAC, mpWA;
    int AC = 0;
    int WA = 0;
    rep(i,M) {
        cin >> p >> S;
        if (S == "AC") mpAC[p] = 1;
        else {
            if (mpAC[p] == 0) ++mpWA[p];
        }
    }
    for (auto x : mpAC) {
        if (x.second) ++AC;
    }
    for (auto x : mpWA) {
        if (mpAC[x.first]) WA += x.second;
    }
    cout << AC << " " << WA << endl;
}
