#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <iomanip>
#include <math.h>
#include <algorithm>
#define hmm "\n"
#define test() int t; cin>>t; while(t--)
#define ll long long int
#define ull unsigned long long
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
void solve()
{
    ll n,m;
    cin>>n>>m;
    ll a[n],b[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
        b[i]=a[i]/2;
    }
    ll o=b[0];
    for(int i=1; i<n; i++){
        o=(o*b[i])/__gcd(o,b[i]);
    }
    for(int i=0; i<n; i++){
        if(o%a[i] != b[i]){
            cout<<"0\n";
            return;
        }
    }
    ll r= m/o;
    cout<<(r+1)/2<<hmm;
    
}
int main()
{
    fastIO
    //test()
    solve();
}
