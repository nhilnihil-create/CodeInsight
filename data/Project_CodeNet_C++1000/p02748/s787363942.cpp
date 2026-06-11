#include <bits/stdc++.h>
using namespace std;

int main()
{
    int A, B, M;
    cin >> A >> B >> M;
    vector<int> a(A), b(B);

    int amin = 100010;
    int bmin = 100010;

    for(int i = 0; i<A; i++){
        cin >> a[i];
        amin = min(amin, a[i]);
    }

    for(int i = 0; i<B; i++){
        cin >> b[i];
        bmin = min(bmin, b[i]);
    }

    int ans = amin + bmin;

    int x, y, c;

    for(int i = 0; i < M; i++){
        cin >> x >> y >> c;
        ans = min(a[x - 1] + b[y - 1] - c, ans);
    }

    cout << ans << endl;

}