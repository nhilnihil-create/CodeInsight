#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define full(a) a.begin(),a.end()
#define stoink stack<ll>
#define vec vector <ll>
#define vg vector<vector<ll> >
#define vgw vector<vector<pair<ll,ll> >
#define pa pair<ll,ll>
#define mp make_pair
#define pb push_back
int main() {
 ll n,a,b;
 cin >> n >> a >> b;
 if ( (abs(b - a)) % 2 == 0)
    cout<< (abs(b - a))/2;
 else
 {
    cout<<min(a-1,n-b) + (b - a)/2 +1;
 }
}
