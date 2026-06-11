#include <bits/stdc++.h>
using namespace std;


#define fast_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
typedef long long int lli;
typedef long long ll;
typedef long double ld;

ll gcd(ll a, ll b){ 
    if (b==0) 
        return a; 
    return gcd(b,a%b); 
} 

signed main(){
    fast_IO;
    int t=1;
    //cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll ans=0;
        while(n>0){
            if(n/500>0){
                ans+=1000*(n/500);
                n-=500*(n/500);
            }
            else if(n/5>0){
                ans+=5*(n/5);
                n-=5*(n/5);
                n=0;
            }
        }
        cout<<ans<<endl;
    }   
    return 0;
}
