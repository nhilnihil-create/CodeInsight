#include <iostream>
#include <cmath>
#include <set>
#include <string>
#include <algorithm>
#include <vector>
#include <bitset>
#include <iomanip>
#include <map>
#include <queue>
#include <numeric>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::bitset;

#define rep(i,n)    for(int i=0; i<(int)n; i++)
#define reps(i,s,e) for(int i=s; i<(int)e; i++)
typedef long double ld;
typedef long long ll;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, ll> pll;

template<class T>
using Graph = vector<vector<T>>;

void printFixedDouble(double d, int fix) {
    cout << std::fixed;
    cout << std::setprecision(fix) << d << endl;
}

int main() {
    int N, M;
    cin >> N >> M;

    int flag = -1;
    int bs[N];
    int evenCount = -1;
    rep(i, N) {
        int b;
        cin >> b;
        b /= 2;
        if (flag == -1) {
            flag = b % 2;
        } else if (b % 2 != flag) {
            cout << 0 << endl;
            return 0;
        }
        if (flag == 0) {
            int tmp = b;
            int count = 0;
            while (tmp % 2 == 0) {
                tmp /= 2;
                count++;
            }
            if (evenCount == -1) {
                evenCount = count;
            } else if (evenCount != count) {
                cout << 0 << endl;
                return 0;
            }
        }
        // cout << b << endl;
        bs[i] = b;
    }


    ll gcd = 1;
    rep(i, N) {
        gcd = gcd * bs[i] / std::__gcd(gcd, (ll)bs[i]);
        // cout << bs[i] << " " << gcd << endl;
    }
    
    cout << ((ll)M/gcd+1)/2<< endl;

}