//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("no-stack-protector")
//#pragma GCC push_options
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC pop_options
//#pragma GCC target("popcnt")
//#pragma GCC target("sse4")
#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define rng(a) a.begin(),a.end()
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define rep(i, n) for (int i = 0; i < n; i++)
#define per(i, n) for (int i = n - 1; i > -1; i--)
#define rer(i, x, n) for (int i = x; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vp;
typedef long double ld;








#define int long long

vector<int> b;
int n, m, v, p;
bool go(int i){
    vector<int> a = b;
    int vv = v;
    vv -= i;
    vv--;
    int q = a[i] + m;
    for(int k = i + 1; k < n; k++){
        if (a[k] == a[i]) vv--;
        else break;
    }
    int j;
    for (j = n - 1; j >= 0; j--){
        if (a[j] <= q) break;
    }
    j++;
    if ((n - j) >= p) return false;
    vv -= (p - 1);
    //if (vv <= 0) return true;
    int ff = m * vv;
    for (int id = i + 1; id < min(j, n - p + 1); id++){
        ff -= (q - a[id]);
    }
    if (ff > 0) return false;
    return true;
}



signed main(){
    cin >> n >> m >> v >> p;
    b.resize(n);
    for (int i = 0; i < n; i++) cin >> b[i];
    sort(rng(b));
    int l = -1, r = n - 1;
    while(r - l > 1){
        int m = (l + r) / 2;
        if (go(m)) r = m;
        else l = m;
    //    cout << l << ' ' << r << ' ' << m << endl;
    }
    cout << n - r;



}
