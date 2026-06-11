#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define REP(i,n) for(int i=0; i<(n); i++)

const long double EPS = 1e-10;
const long long INF = 1e18;
const long double PI = acos(-1.0L);

int main()
{
    int n;
    cin >> n;
    vector<int> x(n);
    REP(i,n) {
        cin >> x[i];
    } 
    int minx = x[0];
    int maxx = x[0];
    REP(i,n) {
        minx = min(minx,x[i]);
        maxx = max(maxx,x[i]);
    } 
    int mind = 1000000000;
    for(int p = minx ;p <= maxx; p++) { 
        int tmp = 0;
        REP(i,n) {
            tmp += (x[i] - p) * (x[i] - p);
        }
        mind = min(mind,tmp);
    }

    cout << mind << endl;


    return 0;
}