#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define ld long double
#define tc() ll t;cin>>t;while(t--)
#define inp(n) ll n;cin>>(n)
#define inp2(n,m) ll n,m;cin>>(n);cin>>(m)
#define inp3(n,m,g) ll n,m,g;cin>>(n);cin>>(m);cin>>(g)
#define inps(s) string s;cin>>(s)
#define fr(i,n) for(ll i=0;i<n;i++)
#define rf(n,i) for(ll i=n-1;i>=0;i--)
#define vi vector<int >
#define vl vector<ll>
#define vd vector<ld>
#define vs vector<string >
#define pii pair<int,int>
#define pci pair<char ,int>
#define pic pair<int ,char>
#define psi pair<string ,int>
#define mii map<int ,int >
#define mci map<char ,int>
#define msi map<string ,int>
#define si set<int >
#define ss set<string>
#define pb push_back
#define mp make_pair
#define ft first
#define sd second
#define mem(a,b) memset(a,b,sizeof(a))
#define mod 1000000007

int main() {
    fast
    int n; 
    cin>> n;
    vi a(n), b(n);
    for(int i=0;i<n;i++)
    cin >>a[i]>>b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    if (n & 1)
        cout << b[n / 2] - a[n / 2] + 1 << endl;
    else {
        cout << b[n / 2] + b[n / 2 - 1] - a[n / 2] - a[n / 2 - 1] + 1 << endl;
    }
}
