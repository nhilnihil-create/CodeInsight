//#pragma GCC target ("avx2")
//#pragma GCC optimization ("O3")
//#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
#define eps 1e-8
#define eq(x,y) (fabs((x)-(y)) < eps)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int>pii;
const ll mod = 1e9+7;
long double PI = acosl(-1);
const ll infl = 1e18;
const int inf = 2e9;
const int nmax = 1e5+5;
const int MAXLG = log2(nmax)+1;
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
//typedef tree< int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ost;


int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin>>n;
    ll total = 0;
    for(int i=1; i<=n; i++) total += 1LL*i*(n+1-i);
    for(int i=1; i<n; i++){
        int u,v;
        cin>>u>>v;
        if(u>v) swap(u, v);
        total -= 1LL*u*(n-v+1);
    }
    cout<<total<<endl;

}
/*

*/
