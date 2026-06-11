#include <bits/stdc++.h>

#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define for1(i, a, b) for (int i = (int)a; i < (int)(b); ++i)
#define rfor1(i, a, b) for (int i=(int)b-1;i>=(int)a;i--)
#define for2(i, a, b) for (int i = (int)a; i <= (int)(b); ++i)
#define for3(i, a, b) for (int i = (int)a; i < (int)(b); i=i+2)
#define for4(i, a, b) for (int i = (int)a; i <= (int)(b); i=i+2)
#define tc(t) int t; cin>>t; while(t--)
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, b;
    cin >> a >> b;
    if (a >= 1 && a <= 9 && b >= 1 && b <= 9) {
        cout << a * b << endl;
    } else {
        cout << "-1" << endl;
    }
}




