
//Inshallah , Boys played well..!!

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define pb push_back
#define pf push_front
#define mk make_pair
#define f(i,j,n) for(ll i=j;i<n;i++)
#define r(i,n,j) for(ll i=n-1;i>=j;i--)
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define Test int t;cin>>t;while(t--)
#define mod 1000000007
#define md 998244353
#define MIN INT_MIN
#define MAX INT_MAX
#define inf LLONG_MAX
#define all(container) container.begin() , container.end()
#define rall(container) container.rbegin() , container.rend()
#define sz(container) (int)container.size()
#define vll vector<long long>
#define vi vector<int>
#define pii pair <int , int>
#define pll pair <ll , ll>
#define fi first
#define se second
#define setp(x) setprecision(x)
#define meme(x,i) memset(x,i,sizeof(x))
const int N = 100005;

void solve() {
    int n;
    cin >> n;
    ll ans=0,sq=sqrt(n);
    f(i,1,sq+1){
        ans+=(ll)((n-1)/i)-i+1;
    }
    if(sq*sq==n)
        sq--;
    cout << 2*ans-sq << endl;
}

int main() {
    fast;
    int t = 1;
    //cin >> t;
    while (t--)  solve();
}