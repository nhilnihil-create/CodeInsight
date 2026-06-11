//Feet don't fail me now
//Take me to the finish line
//Oh, my heart, it breaks every step that I take
//But I'm hoping at the gates, they'll tell me
//that IOI gold is mine
#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <iterator>

#define ios ios_base::sync_with_stdio(0), cout.tie(0), cin.tie(0);
#define S second
#define F first
#define pb push_back
#define nl '\n'
#define NL cout << '\n';
#define EX exit(0)
#define all(s) s.begin(), s.end()
#define no_answer {cout << "NO"; exit(0);}
#define vectors vector<vector<llong> >
#define FOR(i, start, finish, k) for(llong i = start; i <= finish; i += k)

const long long MXN = 2e5 + 10;
const long long MNN = 1e4 + 520;
const long long MOD = 10007;
const long long INF = 1e18;
const long long OO = 1e9;

typedef long long llong;
typedef unsigned long long ullong;

using namespace std;

llong n, m, v, p, b[MXN], ans;

bool check(llong pos){
    llong left = (v - (p - 1)) * m;
    if(b[p] > b[pos] + m) return false;
    for(llong i = 1; i <= n; i++){
        if(b[i] <= b[pos]){
            left -= m;
        }
    }
    for(llong i = pos; i >= p; i--){
        if(b[pos] == b[i]) continue;
        left -= b[pos] + m - b[i];
    }
    if(left <= 0) return true;
    else return false;
}

int main(){
    ios;
    cin >> n >> m >> v >> p;
    for(llong i = 1; i <= n; i++){
        cin >> b[i];
    }
    sort(b + 1, b + n + 1);
    reverse(b + 1, b + n + 1);
    llong l = 1, r = n;
    while(r - l > 1){
        llong m = (r + l) / 2;
        if(check(m)){
            l = m;
        }else{
            r = m - 1;
        }
    }
    cout << (check(r) ? r : l);
}


/*
 010110
 101001
 010100
 101000
 100000
 010000
 1 2
 1 4
 1 5
 2 3
 2 6
 3 4
 */
