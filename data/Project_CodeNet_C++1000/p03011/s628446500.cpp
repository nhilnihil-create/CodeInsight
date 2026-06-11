#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using p = pair<int, int>;
#define INF 1001001001
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repX(i, n ,x) for (int i = x; i < (int)(n); i++)
#define repBack(i, n) for (int i = n; i >= 0; i--)
#define dup(x,y) (((x)+(y)-1)/(y))

int main() {
    vector<int> A(3);
    rep(i,3)cin >> A[i];
    sort(A.begin(),A.end());
    cout << A[0]+A[1] << endl;

    return 0;
}