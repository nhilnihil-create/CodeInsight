#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i <= (int)(n); i++)
using namespace std;


int main(){

    // x ... 動物の総数
    // y ... 足の総数
    int x, y;
    cin >> x >> y;

    const int turtle = 4;
    const int crane = 2;
    bool judge = false;

    rep(i, x) {
        int turtle_count = turtle * i;
        int crane_count = crane * (x - i);

        int count = turtle_count + crane_count;
        if(count == y) {
            cout << "Yes" << endl;
            return 0;
        }

    }

    cout << "No" << endl;
    return 0;
}