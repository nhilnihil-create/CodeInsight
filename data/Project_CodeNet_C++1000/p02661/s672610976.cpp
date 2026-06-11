#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define F first
#define S second
#define def(x) cerr << #x << " is " << x << endl;
#define mod 1000000007
#define pb push_back
#define FOR(i,a,n) for(ll i=a;i<n;i++)
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define all(a) a.begin(),a.end()
const int NUM = 2e5 + 5;
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << endl;
    err(++it, args...);
}

int main(){
    ios
    int num_tests=1; 
    //cin>>num_tests;
    while(num_tests-->0){
        ll n; cin>>n;
        vector<ll> a(n),b(n);
        FOR(i,0,n){
            cin>>a[i]>>b[i];
        }
        sort(all(a));
        sort(all(b));
        // Ranges of the median for X will be median of A to median of B and that is the final answer
        ll meda,medb;
        if(n%2){
            meda = a[n/2];
            medb = b[n/2];
        }
        if(n%2==0){
            meda = a[n/2-1]+a[n/2];
            medb = b[n/2-1]+b[n/2];
        }
        cout<<medb-meda+1;
    }   
}
