#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define pb push_back
#define ld long double
#define f first
#define s second
#define in insert
#define sz(x) (int)x.size()
#define all(x) (x).begin(), (x).end()
#define speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int INF = 1e18 + 5;
const int mod = 1e9 + 7;
const int  N = 2e5 + 314;
const long double pi = 3.1415926535897932384626433832795;
void solve(){
    int x, y, a, b, c;
    cin>>x>>y>>a>>b>>c;
    vi v1(a), v2(b), v3(c);
    map<int, int>u1, u2, u3;
    for(int i = 0; i < a; i++)cin>>v1[i];
    for(int i = 0; i < b; i++)cin>>v2[i];
    for(int i = 0; i < c; i++)cin>>v3[i];
    sort(all(v1)), sort(all(v2)), sort(all(v3));
    reverse(all(v1));
    reverse(all(v2));
    reverse(all(v3));
    vi p(x+y);
    for(int i = 0; i < x; i++)p[i]=v1[i];
    for(int i = x; i < x+y; i++)p[i]=v2[i-x];
    sort(all(p));
    int s = 0;
    for(auto i:p)s+=i;
    int i = 0;
    while(i<c&&i<x+y){
        if(p[i]<v3[i]){
            s-=p[i];
            s+=v3[i];
        }
        i++;
    }
    cout<<s;
}   
signed main(){
    speed;
    int t=1;
    // cin>>t;
    while(t--)solve();
}