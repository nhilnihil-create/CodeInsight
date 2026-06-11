#include <bits/stdc++.h>
using namespace std;

int main() {
    int A,B,M;
    cin >> A >> B >> M;
    vector<int>a(A);
    vector<int>b(B);
    int X = 100001;
    int Y = 100001;
    for(int i = 0; i < A; i++) {
        cin >> a[i];
        X = min(X,a[i]);
    }
    for(int i = 0; i < B; i++) {
        cin >> b[i];
        Y = min(Y,b[i]);
    }
    int ans = X+Y;
    for(int i = 0; i < M; i++) {
        int x,y,c;
        cin >> x >> y >> c;
        ans = min(ans,a[x-1]+b[y-1]-c);
    }
    cout << ans << endl;
}