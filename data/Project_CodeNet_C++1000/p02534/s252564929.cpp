#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define set_bits(a) __builtin_popcount(a)
#define pb push_back
#define pf push_front
#define mod 1000000007
#define M 998244353
#define fi first
#define se second
#define endl '\n'
#define INF 1e18
#define PI 3.14159265358979323846
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);


ll modInverse(ll a, ll b){
 return 1<a ? b - modInverse(b%a,a)*b/a : 1;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    
    freopen("output.txt", "w", stdout);
    #endif
    
    ll n,i;
    cin>>n;
    string s = "ACL";
    string ans = "";
    for(i=0;i<n;i++){
        ans+=s;
    }
    cout<<ans<<endl;
}