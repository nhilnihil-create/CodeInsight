#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstdio>
#include<string>
#include<cstring>
#include<climits>
#include<algorithm>
#include<vector>
#include<cmath>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<deque>
#include<tuple>
#include<list>
#include<unordered_map>
#include<unordered_set>
#include<random>
#include<functional>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pp pair<pair<ll, ll>,pair<ll, ll>>
#define pll pair<ll,ll>
#define pdd pair<double,double>
#define vii vector<int>
#define vll vector<ll>
#define mat vector<vector<ll>>
#define lb lower_bound
#define pb push_back
#define mp make_pair
#define fi first
#define sc second
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep2(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,n) for(ll i=n-1;i>=0;i--)
#define all(x) x.begin(),x.end()
#define LB(v,x) (lower_bound(v.begin(),v.end(),x)-v.begin())
#define UB(v,x) (upper_bound(v.begin(),v.end(),x)-v.begin())
#define ERASE(v) v.erase(unique(v.begin(),v.end()),v.end())
// #define int ll
using namespace std;
const ll INF = (1 << 30 ) - 1;
const ll LLINF = (1LL << 60LL);
const ll MOD = 1000000007;
const ll mod = 998244353;
const ll MAX = 1100000;
const double pi = acos(-1);
const double eps = 1e-10;
ll dx[4] ={1,0,-1,0} , dy[4] ={0,1,0,-1};




signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    string s;
    ll n;
    cin>>n>>s;
    ll a[100010]={1};
    rep2(i,1,100010){
        a[i]=a[i-1]*i;
        a[i]%=MOD;
    }
    if(s[0]=='W'||s[2*n-1]=='W'){
        cout<<0<<endl;
        return 0;
    }
    ll b[200010]={0};
    ll W=0;
    rep2(i,1,2*n){
        if(s[i]=='W') W++;
        if(s[i]==s[i-1]){
            b[i]=1-b[i-1];
        }
        else b[i]=b[i-1];
    }
    ll R=0;
    rep(i,2*n){
        if(b[i]==1) R++;
    }
    if(R!=n){
        cout<<0<<endl;
        return 0;
        
    }
    if(W%2==1){
        cout<<0<<endl;
        return 0;
    }
    ll cnt=0,ans=1;
    rep(i,2*n){
        if(b[i]==1){
            ans*=cnt;
            ans%=MOD;
            cnt--;
        }
        else{
            cnt++;
        }
    }
    /*
    rep(i,2*n){
        cout<<b[i];
    }
    cout<<endl;
    */
    ans*=a[n];
    ans%=MOD;
    cout<<ans<<endl;
    return 0;
}