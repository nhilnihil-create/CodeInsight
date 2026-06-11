#include <bits/stdc++.h>

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 1e9
#define ALL(v) v.begin(), v.end()

using namespace std;
typedef unsigned long long ll;

int main(){
    int w, h, x, y;
    cin >> w >> h>> x >> y;

    std::cout << std::setprecision(9) << std::fixed;
    cout << (double)w*(double)h/2;

    if (x + x == w && y + y == h){
        cout << " 1" << endl;
    }
    else{
        cout << " 0" << endl;
    }
}