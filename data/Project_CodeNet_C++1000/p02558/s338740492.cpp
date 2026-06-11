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





class UnionFind{
public:
    int uf[200005];
    UnionFind(){
        memset(uf,-1,sizeof uf);
    }
    
    int parent(int i){
        if (uf[i] < 0) return i;
        return uf[i] = parent(uf[i]);
    }
    
    void join(int i, int j){
        int pi = parent(i);
        int pj = parent(j);
        if (pi == pj) return;
        if (size(pi) < size(pj)) swap(pi,pj);
        uf[pi] += uf[pj];
        uf[pj] = pi;
        
    }
    
    int size(int i){
        int pi = parent(i);
        return abs(uf[pi]);
    }
    
    void init(){
        memset(uf,-1,sizeof uf);
    }
};





void solve(){

    int n,q;
    cin >> n >> q;
    UnionFind uf;
    rep(i,q){
        int t;
        cin >> t;
        int a,b;
        cin >> a >> b;
        if (t) cout << (uf.parent(a) == uf.parent(b)) << endl;
        else uf.join(a,b);
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


