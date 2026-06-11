#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <climits> // FOO_MAX, FOO_MIN
#include <cmath> 
#include <cstdlib> // abs(int)

using namespace std;

#define roundup(n,d) ( ((n) + ((d)-1)) / (d) )
#define assign_max(into, compared) (into = max((into), (compared)))
#define assign_min(into, compared) (into = min((into), (compared)))
#define rep(i,n) for(long long i = 0;i < n;i++)
using ll = long long;
using ull = unsigned long long;
using llv = vector<long long>;


int main(void){
    ll n;
    cin >> n;
    llv v (n);
    rep(i,n) cin >> v[i];
    sort(v.begin(),v.end());
    rep(i,n-1) {
        if (v[i] == v[i+1]) {
            cout << "NO" << endl; return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}