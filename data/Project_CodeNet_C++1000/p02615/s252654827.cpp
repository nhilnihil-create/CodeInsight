#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include <set>
#include <math.h>
#include <queue>
#define rep(i,n) for (int i = 0; i < (n); ++i)
typedef long long ll;
using namespace std;

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    sort(a.rbegin(),a.rend());
    ll sum=0;
    int t=n-1;
    rep(i,n){
        int lim=2;
        if(i==0) lim=1;
        rep(j,lim) {
            if(t>0) {
                sum+=a[i];
                t--;
            }
        }
    } 
    cout << sum << endl;
    return 0;
}
