
// Problem : E - Yutori
// Contest : AtCoder - AtCoder Beginner Contest 161
// URL : https://atcoder.jp/contests/abc161/tasks/abc161_e
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

int n,k,c;
string s;

signed main(){
    io;
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cin>>n>>k>>c>>s;
    vi l(k+1),r(k+1);
    int prev = -1, cnt = 0;
    for(int i=0;i<n;i++){
        if((prev == -1 || i-prev>c) && s[i] == 'o') l[++cnt] = i, prev = i;
        if(cnt == k) break;
    }
    cnt = k+1, prev = -1;
    for(int i=n-1;i>=0;i--){
        if((prev == -1 || prev-i>c) && s[i] == 'o') r[--cnt] = i, prev = i;
        if(cnt == 1) break; 
    }
    vi ans;
    for(int i=1;i<=k;i++){
        if(l[i] == r[i]) ans.pb(l[i]);
    }
    for(auto i : ans) cout<<i+1<<endl;
    return 0;
}
