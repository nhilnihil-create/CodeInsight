// RWWW
// WW[WR]RR WRを削除、RRR|WWWにする。
// WRWRWR
// WWWWRWWWW => WWW[W]WWWW
// WWWRRRWWW => [RRR]RRRWWW
// WRWWWWWWW => W[W]WWWWWW / [R]RWWWWWWW
// 全部のRの個数をかぞえる AR
// 全部のWの個数をかぞれる AW
// RR[WR]WW => RR[RW]WW
// RR[WR]WWW ==>

// W[WR]R R[WR]W 
#include <iostream>
#include <vector>
#include <deque>
#include <tuple>
#include <algorithm>
#include <iterator> // std::back_inserter
#include <climits>
#include <sstream>

#define swap(x,y) do {auto tmp = x; x = y; y = tmp;} while(0)
using namespace std;

typedef unsigned long ll;

ll n;
char a[200001];

int main()
{
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    ll counter = 0;
    int rp = n-1;
    int lp = 0;
    while(1) {
//        cout << "lp=" << lp << " rp=" << rp << " "; for (int i=0; i<n; i++) { cout << a[i]; } cout << endl;
        // WR
        //    WRRRRR WWWWWWWWR
        // => RRRRRR WWWWWWWWR
        // => WRRRRR WWWWWWWWW
        // => RRRRRR WWWWWWWWW

        if (a[lp] == 'W' && a[rp] == 'R') {
            swap(a[lp],a[rp]);
            counter++;
            lp++; rp--;
            if (lp >= rp) {
               break;
            }
            continue;
        }
        if (a[lp] == 'R' && a[rp] == 'R') {
            lp++;
            if (lp >= rp) {
               break;
            }
            continue;
        }
        if (a[lp] == 'W' && a[rp] == 'W') {
            rp--;
            if (lp >= rp) {
               break;
            }
            continue;
        }
        if (a[lp] == 'R' && a[rp] == 'W') {
            lp++; rp--;
            if (lp >= rp) {
                break;
            }
        }
    }
//    cout << "-- lp=" << lp << " rp=" << rp << " ";    for (int i=0; i<n; i++) { cout << a[i]; } cout << endl;
    cout << counter << endl;
}
