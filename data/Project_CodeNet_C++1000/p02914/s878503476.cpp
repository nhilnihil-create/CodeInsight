#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <climits>
#include <cmath>
#include <complex>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <cstdint>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
#define inf 1000000007
#define mod 1000000007
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)

int main(){
    int n;
    cin >> n;
    vector<ll>a(n);
    ll p = 0;
    rep(i,n){
        cin >> a[i];
        p ^=a[i];
    }
    rep(j,60){
        if((p>>j)&1){
            rep(i,n){
                if((a[i]>>j)&1){
                    a[i] ^= (1LL<<j);
                }
            }
        }
    }
    rep(i,min(60,n)){
        sort(a.begin(),a.end(),greater<ll>());
        ll c = -1;
        rep(j,60){
            if((a[i]>>j)&1){
                c = j;
            }
        }
        if(c==-1)break;
        rep(j,n){
            if(i!=j){
                if((a[j]>>c)&1){
                    a[j]^=a[i];
                }
            }
        }
    }
    sort(a.begin(),a.end(),greater<ll>());
        
    int m = min(n,60);
    cerr << bitset<60>(p) << endl;
    rep(i,n){
        cerr << bitset<60>(a[i]) << endl;
    }
    ll q = 0;
    rep(i,m){
        q ^=a[i];
    }
    cout << q + (p^q) << endl;
    return 0;
}