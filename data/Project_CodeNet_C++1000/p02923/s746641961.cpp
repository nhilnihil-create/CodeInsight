#include <bits/stdc++.h>
using namespace std;


#define fast_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define pb push_back
#define F first
#define S second
#define int long long int
#define ll long long
#define ld long double

bool isPrime(ll n){if(n<2)return false;for(ll i=2;i*i<=n;++i){if(n%i==0){return false;}}return true;}

ll lcm(ll x,ll y){
    return (x*y)/(__gcd(x,y));
}

signed main(){
    fast_IO;
    int t=1;
    //cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int c=0;
        int m=-1;
        for(int i=0;i<n-1;i++){
        	if(a[i]>=a[i+1]){
        		c++;
        	}
        	else{
        		m=max(m,c);
        		c=0;
        	}
        }
        m=max(m,c);
        cout<<m<<endl;
    }   
    return 0;
}
