#include <cstdio>
#include <random>
#include <cassert>
#include <algorithm> 
#include <iostream>
#include <chrono>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <bitset>
#define pb push_back
#define mk make_pair
#define eb emplace_back
#define eps 1e-8
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define int long long
using namespace std;
typedef long double ld;
typedef unsigned int ui;
typedef pair<int,int> pii;
typedef tuple<int, int, int> tiii;
typedef vector<int> vii;
typedef vector<long double> vd;
const int inf = 1e9;
const long long INF = 1e18;
const int M = 1e9 + 7;
int vec[66];

bool ins(int x) {
    for(int i = 60; i >= 0; --i) {
        if(x >> i & 1) {
            if(!vec[i]) {
                vec[i] = x;
                return 1;
            } else {
                x ^= vec[i];
            }
        } 
    }
    return 0;
}

bool chk(int x) {
    for(int i = 60; i >= 0; --i) {
        if(x >> i & 1) {
            if(!vec[i]) {
                return 1;
            } else {
                x ^= vec[i];
            }
        } 
    }
    return 0;
}


signed main() {
    int T;
    cin >> T;
    while(T--) {
        memset(vec, 0, sizeof(vec));
        int n;
        cin >> n;
        vector<int> a, b;
        vector<int> A(n);
        for(int i = 0; i < n; ++i) {
            cin >> A[i];
        }
        string s;
        cin >> s;
        bool ok = 1;
        for(int i = n - 1; i >= 0; --i) {
            if(s[i] == '0') {
                ins(A[i]);
            } else {
                if(chk(A[i])) {
                    puts("1");
                    ok = 0;
                    break;
                }
            }
        }
        if(ok) {
            puts("0");
        }
    }
    return 0;
}