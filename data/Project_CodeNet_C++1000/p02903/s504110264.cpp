#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
#define forr(i,a,n) for (int i = (a); i < (n); ++i)
#define rforr(i,a,n) for (int i = (a); i > (n); --i)
#define ALL(x) (x.begin(),x.end())
#define LEN(X) ((int)(X).size())
#define CASET int _T; cin >> _T; forr(caset,0,_T)
 
int main() {
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
 
    int h,w, a, b; cin >> h >> w >> a >> b;
    vi col(w,0), row(h,0);
    bool grid[1000][1000] = {};

    forr(i,0,b) forr(j,0,a) grid[i][j] = true;
    forr(i,b,h) forr(j,a,w) grid[i][j] = true;

    forr(i,0,h) {
        forr(j,0,w) cout << grid[i][j];
        cout << '\n';
    } 

    return 0;
}
