#include<bits/stdc++.h>
#define forr(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
#define ALL(a) (a.begin()),(a.end())
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll, ll> LP;
const ll LINF = 1LL<<60;
const int INF = 1001001001;

/* --------------------------------------------------- */

int main() {
    int n;
    cin >> n;
    int odd = 0;
    rrep(i, n) {
        if(i % 2 == 1) odd++;
    }
    double ans = (double)odd / n;
    printf("%.10f\n", ans);


    return 0;
}