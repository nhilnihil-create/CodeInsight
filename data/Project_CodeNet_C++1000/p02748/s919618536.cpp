#include <bits/stdc++.h>
#include <algorithm>
#define rep(i, n) for (int i=0; i<n; ++i)
#define all(obj) (obj).begin(),(obj).end()
using namespace std;
typedef long long ll;
long long GCD(long long x, long long y) { return y ? GCD(y, x%y) : x; }

int main(){
    int A, B, M;
    cin >> A >> B >> M;
    vector<int>a(A);
    vector<int>b(B);
    rep(i, A) cin >> a[i];
    rep(i, B) cin >> b[i];
    int miA = *min_element(a.begin(), a.end());
    int miB = *min_element(b.begin(), b.end());
    int price = miA + miB;
    rep(i, M){
        int x, y, c;
        cin >> x >> y >> c;
        price = min(price, a[x-1]+b[y-1]-c);
    }
    cout << price << endl;
    return 0;
}
