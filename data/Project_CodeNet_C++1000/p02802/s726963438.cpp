#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
typedef pair<int, int> pair;
const int inf = 1000000000; //10^9
const ll inff = 1000000000000000000; //10^18

int WA[100100];
bool AC[100200];

int main(){
    int n, m;
    cin >> n >> m;

    int ac = 0;
    int pena = 0;
    rep(i, n) {
        WA[i] = 0;
        WA[i] = false;
    }
    rep(i, m) {
        int P;
        string S;
        cin >> P >> S;
        if (AC[P-1]) continue;
        if (S == "AC") {
            AC[P-1] = true;
            ac++;
            pena += WA[P-1];
        }
        else WA[P-1]++;
    }
    cout << ac << ' ' << pena << endl;
    return 0;
}