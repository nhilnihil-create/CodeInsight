#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll t1,t2;
    ll a1,a2,b1,b2;
    cin>>t1>>t2>>a1>>a2>>b1>>b2;
    if(t1*a1+t2*a2==t1*b1+t2*b2){
    	cout << "infinity"<<endl;
    	return 0;
    }
    if((a1<b1&&a2<b2)||(a1>b1&&a2>b2)){
    	cout << 0<<endl;
    	return 0;
    }
    if(a1<b1){
    	swap(a1,b1);
    	swap(a2,b2);
    }
    ll m=t1*a1-t1*b1;
    ll n=-t2*a2+t2*b2;
    if(m>n){
    	cout << 0<<endl;
    	return 0;
    }
    ll ans=1;
    ll maki=n-m;
    ll niko=m/maki;
    ans+=niko*2;
    if(m%maki==0){
    	ans--;
    }
    cout<<ans<<endl;

    return 0;
}
