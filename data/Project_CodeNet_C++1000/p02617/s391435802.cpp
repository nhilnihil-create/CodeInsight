#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>

using namespace std;
typedef long long ll;
typedef long double ld;

ll temp1,temp2,temp;
char tempc;

#define forn(i,n) for(int i=0;i<int(n);i++)

#define N 1000000007
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define pi pair<int,int>
#define pl pair<ll,ll>
#define int ll
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL)

ll binpow(ll a, ll b)
{
    a%=N;b=b%(N-1);
    ll res=1;
    while(b>0)
    {
        if(b&1) res=res*a%N;
        a=a*a%N;
        b>>=1;
    }
    return res%N;
}

int simpow(int a,int b)
{
    // b=b%(N-1);
    ll res=1;
    while(b>0)
    {
        if(b&1) res=res*a;
        a=a*a;
        b>>=1;
    }
    return res;
}

int gcd(int a,int b)
{
    if (b == 0) 
        return a; 
    return gcd(b, a % b);  
}

int mini(int a,int b)
{
    if(a<b) return a;
    return b;
}

struct DSU {
    vector<int> sz;
    vector<int> parent;
 
    void make_set(int v) {
        parent[v] = v;
        sz[v] = 1;
    }
 
    int find_set(int v) {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }
 
    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (sz[a] < sz[b])
                swap(a, b);
            parent[b] = a;
            sz[a] += sz[b];
        }
    }
 
    DSU(int n) {
        sz.resize(n+1);
        parent.resize(n+1);
        for (int i = 1; i <= n; i++) make_set(i);
    }
};

signed main()
{
    fast;
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int n; cin >> n;
    int ans=(n*(n+1)*(n+2))/6;
    vector <int> v(2);
    forn(i,n-1)
    {
        cin >> v[0] >> v[1];
        sort(v.begin(),v.end());
        ans-=(v[0]*(n+1-v[1]));
    }
    cout << ans << endl;
}