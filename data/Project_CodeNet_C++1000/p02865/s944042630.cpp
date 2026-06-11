#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define pii pair<int,int>
#define pll pair<ll, ll>
#define vi vector<int>
#define IO ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
#define read(FILE)  freopen(FILE, "r", stdin);
#define out(FILE) freopen(FILE, "w", stdout);
#define all(x) x.begin(),x.end()
#define rep(i,m,n) for(int i=m ; i<n ; i++)
#define forr(i,m,n) for(int i=m ; i<=n ; i++)
#define endl '\n'
#define pb push_back
#define pff push_front
#define re return
const int N = 1e5 + 5;
using namespace std;
int main()
{
    IO;
    int n; cin>>n;
    int l=1,r=n-1,cnt=0;
    while(l<r){
        if((l+r)==n){
            cnt++;
            r--;
        }
        else if((l+r)<n){
            l++;
        }
        else if((l+r)>n){
            r--;
        }
    }

    cout<<cnt;



}
