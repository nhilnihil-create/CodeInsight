#include<bits/stdc++.h>
#define ll long long
#define MAX 1000000000
#define INF 1000000 
#define M 1000000007
#define PI 2 * acos(0.0)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std; 
int main(){
    fast_io 
    ll n,m;
    cin>>n>>m;
    ll y = (n*(n-1))/2;
    ll x = (m*(m-1))/2;
    cout<<x+y<<endl;
    return 0;
}
