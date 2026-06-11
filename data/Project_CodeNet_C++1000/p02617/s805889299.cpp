#pragma comment(linker, "/STACK: 2000000")
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define clock (clock() * 1000.0 / CLOCKS_PER_SEC)
#define dbg(x) cout << #x << '=' << x << '\n';
#define ll long long
#define double long double
#define x first
#define y second
#define vi vector <int>
#define L nod<<1
#define R ((nod<<1)|1)
#define int ll
#define PI 3.14159265358979
const ll mod=1000000007;
int n, ans;

int32_t main(){
    ios_base :: sync_with_stdio(0); cin.tie(); cout.tie();
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    cin>>n;
    for(int i=1; i<=n; i++) ans+=i*(i+1)/2;
    //cout<<ans<<endl;
    for(int i=1; i<n; i++){
        int x, y;
        cin>>x>>y;
        ans-=min(x, y)*(n-max(x, y)+1);
    }
    cout<<ans;
}

