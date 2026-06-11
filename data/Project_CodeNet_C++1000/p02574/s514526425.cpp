#include <map>
#include <algorithm>
#include <cassert>
#include <climits>
#include <complex>
#include <cstdio>
#include <string>
#include <iostream>
#include <queue>
#include <string>
#include <tuple>
#include <vector>
#include <numeric>
using namespace std;
using ll = long long;
using ld = long double;

template<class T> bool chmin(T &a, T b) { return a>b?(a=b,true):false; }
template<class T> bool chmax(T &a,T  b) { return a<b?(a=b,true):false; }
#define forn(i,x,y) for(int i=(x);i<(int)(y);i++)
#define rep(i,y) for(int i=0;i<(int)(y);i++)
#define repb(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define all(a) (a).begin(), (a).end()
#define uni(a) (a).erase(unique(all(a)), (a).end())
#define bit(n, i) (((n) >> (i)) & 1)
#define bitcount(n) __builtin_popcountll(n)

int N;
int a[1000100];
bool inv[1000100];
bool note[1000100];
int main() {
    bool glb_non_pairwise = false;
    cin >> N;
    rep(i,N) {
        cin >> a[i];
        if (inv[a[i]]&&a[i]!=1) glb_non_pairwise=true;
        inv[a[i]] = true;
    }
    int p = gcd(a[0],a[1]);
    rep(i,N) {
        p=gcd(p,a[i]);
    }
    bool setwise = false;
    if (p==1) setwise = true;
    bool non_pairwise = false;
    for(int i=2;i<1000100;i++) {
        if (note[i]) continue;
        ll mul=1;
        int cnt=0;
        while(i*mul<1000100) {
            note[i*mul] = true;
            if (inv[i*mul]) cnt++;
            mul++;
        }
        if (cnt > 1) {
            non_pairwise = true;
            break;
        }
    }
    if (!non_pairwise&&!glb_non_pairwise) {
        cout << "pairwise coprime" << endl;
        return 0;
    } else if (setwise) {
        cout << "setwise coprime" << endl;
        return 0;
    } else {
        cout << "not coprime" << endl;
    }
}