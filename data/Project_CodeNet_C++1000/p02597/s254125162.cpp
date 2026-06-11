#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using V = vector<int>;

int main(int argc, char const *argv[])
{
    int n; cin >> n;
    string c; cin >> c;
    int r = 0;
    rep(i,n) if (c[i] == 'R') r++;
    int WtoR = 0, RtoW = 0;
    rep(i,n) {
        if (i < r && c[i] == 'W') WtoR ++;
        if (i >= r && c[i] == 'R') RtoW ++;
    }
    int swap = min(WtoR,RtoW);
    int change = max(WtoR,RtoW)-swap;


  
    cout << swap+change << endl;

    return 0;
}
