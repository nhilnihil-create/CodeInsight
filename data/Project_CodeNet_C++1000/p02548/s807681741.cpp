#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long long unsigned int llu;
#define pb push_back
#define PI 3.1415926535897932384626433832795
#define mod 1000000007
#define F first
#define S second
#define ALL(a) (a).begin(),(a).end()
#define YUGEN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define lp(i,start,end) for(int i=start;i<end;i++)
#define MAX 105
#define BPC(x)  __builtin_popcountll(x)
#define test() ll t; cin>>t; while(t--)
#define gcd(a,b)  __gcd(a,b)
#define SIZE 26
ll gcd(ll a,ll b) {if (a==0) return b;return gcd(b%a,a);}

int main()
 {
    YUGEN;
    ll n;
    cin>>n;
    int ans=0;
    for(int i=1;i<n;i++)
    {
      ans+=(n-1)/i;
    }
    cout<<ans;
    

 }


