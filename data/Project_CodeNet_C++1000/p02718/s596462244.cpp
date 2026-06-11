#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define debug1(x) cerr<<#x<<" : "<<x<<"\n";
#define debug2(x,y) cerr<<#x<<" : "<<x<<"\t"<<#y<<" : "<<y<<"\n";
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    freopen("input.txt", "rt" , stdin);
//    freopen("output.out", "wt",stdout);


int main() {
    IOS;
    ll n,m;
    cin>>n>>m;
    ll a[n],sum=0;
    for(ll i=0;i<n;i++){
        cin>>a[i];sum+=a[i];
    }
    ll x =sum/(4*m),k=0;
    if (sum % (4 * m) != 0) x++;

    for(ll i=0;i<n;i++){

        if(a[i]<x);else k++;

    }
    if(k<m)cout<<"No";else cout<<"Yes";
    return 0 ;
}
