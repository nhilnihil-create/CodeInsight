#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <fstream>
#include <numeric>
using namespace std;
typedef long long int ll;

#define EPS (1e-7)
#define INF 1e18
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))
#define PI (acos(-1))

#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define rep(i, init, n) for(int i = init; i <(int)(n); i++)

int main() {
    ll N;
    cin >> N;
    string c;
    cin >> c;
    c = 'R' + c + 'W';
    ll r = N + 1;
    ll l = 0;
    ll ans = 0;
    bool a = false;
    while(l < r){
        while(c[l] == 'R'){
            l++;
            if (r == l) {
                a = true;
                break;
            }  
        }
        if (a){
            break;
        }


        while(c[r] == 'W'){
            r--;
            if (r == l) {
                a = true;
                break;
            }
        }
        if (a){
            break;
        }


        c[r] = 'W';
        c[l] = 'R';
        ans++;
        if (l + 1 == r) break;

    }
    cout << ans << endl;

    return 0;
}

