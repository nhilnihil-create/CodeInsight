
// Problem : B - 123 Triangle
// Contest : AtCoder - AtCoder Grand Contest 043
// URL : https://atcoder.jp/contests/agc043/tasks/agc043_b
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define db long double
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define vl vector<ll>
#define vii vector<pii>
#define mi map<int,int>
#define ml map<ll,ll>
#define mii map<pii,int>
#define fi first
#define se second
#define all(a) (a).begin(),(a).end()
#define sz(x) (int)x.size()
#define mod 1000000007
#define MAX 4294967295
#define EPS 1e-9
#define io ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define MAXN 15000005
#define inf 1e10
#define PI acos(-1.0)
#define int long long

int n;
string s;
vi a(1000005);

bool check(int n, int k){ return (n&k) == k; }

int getXor(){
    int ret = 0;
    for(int i=0;i<n;i++){
        if(a[i]%2) ret ^= check(n-1,i);
    }
    return ret;
}

signed main(){
    io;
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cin>>n>>s;
    for(int i=0;i<n;i++) a[i] = s[i]-'1';
    if(getXor()) return cout<<1, 0;
    bool exist = false;
    for(int i=0;i<n;i++) exist |= a[i]==1;
    if(exist) return cout<<0, 0;
    for(int i=0;i<n;i++) a[i] /= 2;
    if(getXor()) cout<<2;
    else cout<<0;
    return 0;
}
