#include<bits/stdc++.h>

using namespace std;
#define ll  long long
#define ld  long double
#define endl '\n'
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const ll MOD = (ll) 1e9 + 7;
const double PI = 3.141592653589793238463;
const int MAXN = 300005;


int main() {
    FAST
    ll n,k,dif;
    cin>>n>>k>>dif;
    n=abs(n);
    ll num=n/dif;
    if(n%dif==0){
       if(num>=k){
           cout<<n-(ll)(k*dif)<<endl;
       }
       else{
           if((k-num)%2==0){
               cout<<0<<endl;
           }
           else{
               cout<<dif<<endl;
           }
       }
    }
    else{
        if(num>=k){
            cout<<n-(ll)(k*dif)<<endl;
        }
        else {
            ll mod = n % dif;
            k -= num;
           if(mod<llabs(mod-dif)){
               if(k%2==0){
                   cout<<mod<<endl;
               }
               else{
                   cout<<min(llabs(mod-dif),mod+dif)<<endl;
               }
           }
           else{
               k--;
               if(k%2==0){
                   cout<<llabs(mod-dif)<<endl;
               }
               else{
                   cout<<min(llabs((mod-dif)-dif),mod)<<endl;
               }
           }
        }

    }
    return 0;
}
