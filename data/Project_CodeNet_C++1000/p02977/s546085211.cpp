#include <bits/stdc++.h>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <iostream>
#include <bitset>
#include <cassert>
#include <queue>
#include <random>
#include <stack>
#include <iomanip>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)
#define repf(i, a, b) for (ll i = (ll)a; i < (ll)b; i++)
#define repr(i, a, b) for (ll i = (ll)a; i > (ll)b; i--)
#define repv(x, arr) for (auto &x : arr)
#define all(v) (v).begin(), (v).end()
#define vec(name, num) vector<ll> name((num), 0);
#define mp(a, b) make_pair(a, b)
#define op(i) cout << (i) << endl;
#define F first
#define S second
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pdd;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<int> vii;
typedef vector<vii> vvii;
const ll mod = 1e9 + 7;
const int infi = 2147483600;
const ll infl = 1e17;


int main()
{
    int n;
    cin >> n;
    int now = n;
    int cnt = 0;
    while (now>1){
        if (now%2==1)
            break;
        cnt++;
        now /= 2;
    }
    if (now==1)
        cout << "No" << endl;
    
    else {
        while (now > 1)
        {
            cnt++;
            now /= 2;
        }
        cout << "Yes" << endl;
        vll x = {1, 2, 3, n + 1, n + 2, n + 3};
        rep(i, 5) cout << x[i] << " " << x[i + 1] << endl;
        if (n%2==1){
        repf(i,2,n/2+1){
            cout << 1 << " " << 2 * i << endl;
            cout << 2 * i << " " << 2 * i + 1 << endl;
            cout << 1 << " " << 2 * i + 1 + n << endl;
            cout << 2 * i + 1 + n << " " << 2 * i + n << endl;
        }
        }
        else {
            repf(i,2,n/2){
                cout << 1 << " " << 2 * i << endl;
                cout << 2 * i << " " << 2 * i + 1 << endl;
                cout << 1 << " " << 2 * i + 1 + n << endl;
                cout << 2 * i + 1 + n << " " << 2 * i + n << endl;
            }
            int z = n + 1;
            int x = 1;
            int y = 0;
            repf(k,2,cnt+1){
                if((z>>k)&1){
                    x += (1 << k);
                    break;
                }
            }
            y = (z ^ x);
            cout << x+n << " " << n << endl;
            cout << y << " " << 2 * n << endl;
        }
    }
    
}
