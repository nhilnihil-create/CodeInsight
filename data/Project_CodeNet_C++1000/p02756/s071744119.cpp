#include <bits/stdc++.h>
using namespace std;

#define rp(i, k, n) for (int i = k; i < n; i++)
typedef long long ll;
typedef double ld;



template<class T>inline bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>inline bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF = 1ll << 60;
const ll MOD = 1e9 + 7ll;
const double PI=3.14159265358979323846;




int main() {
    string S;
    cin >> S;
    int Q;
    cin >> Q;
    bool r = false;
    rp(i, 0, Q) {
        int T;
        scanf("%d", &T);
        if(T == 1) r = !r;
        if(T == 2) {
            int f; string c;
            cin >> f >> c;
            if(f == 1) {
                if(r) {
                    S += c;
                }
                 else S.insert(0, c);
            }
            else {
                if(r) {
                    S.insert(0, c);
                }
                else S += c;
            }            
        }
    }
    if(r) reverse(S.begin(), S.end());
    cout << S << endl;
    return 0;

}