#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <cstdio>
#include <string>
#include <cmath>
#include <queue>
#include <tuple>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <random>
#include <set>
#include <stack>
#include <time.h>

//#include <bits/stdc++.h>
#define maxs(x,y) x = max(x,y)
#define mins(x,y) x = min(x,y)
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define repr(i, n) for (int i = (n) - 1; i >= 0; i--)
#define FOR(i,i0,n) for(int (i)=(i0);(i)<(n);(i)++)
#define FORR(i,i0,n) for(int (i)=(n)-1; (i)>=(i0);(i)--)
#define SORT(x) sort(x.begin(),x.end())
#define SORTR(x) sort(x.begin(),x.end(),greater<vector<int>>())

#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple

using namespace std;
using ll = long long;
typedef std::pair<int, int> pii;
typedef std::pair<int, double> pid;
typedef std::vector<int> vi;
typedef std::vector<pii> vii;

#define PI 3.14159265358979323846264338327950L
const int mod = 1e9+7;








struct BIT{
public:
    int size;
    vector<long long> values;
    BIT(int n){
        size = n;
        values.assign(size+1,0);
    }
    
    void increment(int index, int val){
        index++;
        while(index <= size){
            values[index] += val;
            index += index&(-index);
        }
    }
    
    long long sum(int l, int r){
        return sum(r)-sum(l);
    }
    
    long long sum(int index){
        long long ret = 0LL;
        while(index){
            ret += values[index];
            index ^= index&(-index);
        }
        return ret;
    }
};




void solve(){


    int n,q;
    cin >> n >> q;
    BIT bit(n);
    vi a(n);
    rep(i,n) cin >> a[i];
    
    rep(i,n){
        bit.increment(i,a[i]);
    }
    rep(i,q){
        int t;
        cin >> t;
        if (t==0){
            int p,x;
            cin >> p >> x;
            bit.increment(p,x);
        }
        else{
            int l,r;
            cin >> l >> r;
            cout << bit.sum(l,r) << endl;
        }
    }

}




int main() {
    int T;
    //cin >> T;
    T = 1;
    while (T--) {
        solve();
        cout << endl;
    }
}


