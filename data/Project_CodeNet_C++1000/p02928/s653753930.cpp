#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//#define eps 1e-8
//#define eq(x,y) (fabs((x)-(y)) < eps)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int>pii;
const int mod = 1e9+7;
long double PI = acosl(-1);
const ll infl = 3e18+100;
const int inf = 1e8+100;
const int nmax = 1e5+5;
const int MAXLG = log2(nmax)+1;
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
//typedef tree< int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ost;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    ll n,k;
    cin>>n>>k;
    vector<int>v(n);
    for(int &x : v) cin>>x;
    ll ans = 0;
    for(int i=0; i<n; i++) for(int j=0; j<n; j++)if(v[i]>v[j]){
        if(i<j){
            ans = (ans + k*(k+1)/2 % mod) % mod;
        }
        else{
            ans = (ans + k*(k-1)/2 % mod) % mod;
        }
    }
    cout<<ans<<endl;

}
