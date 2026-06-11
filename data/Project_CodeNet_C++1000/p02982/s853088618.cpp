#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int x[15][15];

int main() {
    ios_base::sync_with_stdio(0);
    int n, d; cin >> n >> d;
    for (int i=0;i<n;i++) {
        for (int j=0;j<d;j++) cin >> x[i][j];
    }

    int cnt = 0;
    for (int i=0;i<n;i++) for (int j=i+1;j<n;j++) {
        int dd = 0;
        for (int k=0;k<d;k++) dd += (x[i][k]-x[j][k])*(x[i][k]-x[j][k]);
        int pp = sqrt(dd);
        if (pp*pp==dd) cnt++;
    }
    cout << cnt << endl;
}
