#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0;i < n;i++)
#define llong long long
using namespace std;

int main()
{
    llong H, W;
    while (true) {
        cin >> H >> W;
        if (H == 0 && W == 0) {
            break;
        }
        REP(i,H){
            REP(j,W) cout << "#";
            cout << endl;
        }
        cout << endl;
    }


    return 0;
}