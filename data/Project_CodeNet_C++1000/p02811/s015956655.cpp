/***
coded by adarsh
***/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll; 
typedef long double ld;
typedef vector<ll> vec; 
typedef vector<vector<ll>> vec2;
typedef pair<ll,ll> pair1;
typedef pair<string,ll> pair2;
typedef pair<ll,string> pair3;
typedef pair<string,string> pair4;
#define fl(i,a,b) for(i=a;i<b;i++)
#define rfl(i,a,b) for(i=b-1;i>=a;i--)
#define f first
#define s second

int main() 
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll a,b;cin>>a>>b;
    if(a*500>=b) cout<<"Yes";
    else cout<<"No";
    return 0;
}
