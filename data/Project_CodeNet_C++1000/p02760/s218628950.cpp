#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define F first
#define S second
const int A = 2e5 + 2;
const int mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n, a[3][3];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cin >> a[i][j];
    cin >> n;
    bool mark[3][3] = {};
    while(n--) {
        int x;
        cin >> x;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (x == a[i][j]) 
                    mark[i][j] = 1;
    }
    bool done = ((mark[0][0] && mark[1][1] && mark[2][2]) || (mark[0][2] && mark[1][1] && mark[2][0]));
    for (int i = 0; i < 3; i++) {
        int cnt = 0;
        for (int j = 0; j < 3; j++)
            if (mark[i][j]) 
                cnt++;
        if (cnt == 3) done = 1;
    }
    for (int j = 0; j < 3; j++) {
        int cnt = 0;
        for (int i = 0; i < 3; i++)
            if (mark[i][j]) 
                cnt++;
        if (cnt == 3) done = 1;
    }
    cout << (done ? "Yes" : "No");
    return 0;
}