#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin>>n;
    set<ll> s,g;
    s.insert(2LL);
    s.insert(n);
    ll maki=ll(sqrt(n));
    for(ll i=3LL;i<=maki;i++){
    	ll num=i;
    	while(num<n){
    		num*=i;
    		if(num==n){
    			s.insert(i);
    		}
    	}
    }
    vector<ll> v;

    for(ll j=2LL;j<=maki;j++){
    	if(n%j==0){
    		v.pb(j);v.pb(n/j);
    	}
    	
    }
    for(auto& i:v){
    	ll m=n;
        while(m>=i){
        	if(m%i==0)m/=i;
        	else m%=i;
        }
        if(m==1LL)s.insert(i);
    }


    n--;
    for(ll i=1LL;i<=maki;i++){
    	if(n%i==0){
    		s.insert(i);
    		s.insert(n/i);
    	}
    }
    s.erase(1LL);
    cout << s.size() <<endl;
    /*for(auto& i:s)cout << i<<" ";
    cout << endl;*/
    return 0;
}
