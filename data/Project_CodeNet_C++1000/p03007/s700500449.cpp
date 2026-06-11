#include <bits/stdc++.h>
#define owo(i,a, b) for(int i=(a);i<(b); ++i)
#define uwu(i,a, b) for(int i=(a)-1; i>=(b); --i)
#define senpai push_back
#define ttgl pair<int, int>
#define ayaya cout<<"ayaya~"<<endl
 
using namespace std;
/*#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
gpu_hash_map<int, int> mp;*/
using ll = long long;
using ld = long double;
const ll MOD = 1000000007;
const ll root = 62;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
ll binpow(ll a,ll b){ll res=1;while(b){if(b&1)res=(res*a)%MOD;a=(a*a)%MOD;b>>=1;}return res;}
ll modInv(ll a){return binpow(a, MOD-2);}
const double PI = acos(-1);
const double eps = -1e6;
const int INF = 0x3f3f3f3f;
const int NINF = 0xc0c0c0c0;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll NINFLL = 0xc0c0c0c0c0c0c0c0;
const int mxN = 100001;
int n;
int arr[mxN];
vector<ttgl> ans;
int neg, posi;
int main() {
    //freopen("greedy.in", "r", stdin);
    //freopen("greedy.out", "w", stdout);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    cin.tie(0)->sync_with_stdio(0);
    cin>>n;
    owo(i, 0, n) {
        cin>>arr[i];
        if(arr[i]<0) {
            neg++;
        }else posi++;
    }
    sort(arr, arr+n);
    if(neg==0) {
        neg++;
        posi--;
    }else if(posi==0) {
        posi++;
        neg--;
    }
    int nn = neg;
    if(neg>0&&posi>0) {
        while(neg<n-1) {
            ans.senpai({arr[0], arr[neg]});
            arr[0]-=arr[neg];
            neg++;
        }
        int idx = 0;
        while(idx<nn) {
            ans.senpai({arr[n-1], arr[idx]});
            arr[n-1]-=arr[idx];
            idx++;
        }
    }
    cout<<arr[n-1]<<"\n";
    for(auto p: ans) {
        cout<<p.first<<" "<<p.second<<"\n";
    }
    return 0;
}