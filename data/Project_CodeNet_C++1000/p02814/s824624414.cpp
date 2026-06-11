#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
ll a[100005];
ll lc(ll a, ll b){
    ll g = __gcd(a,b);
    return (a*b)/g;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    ll m;
    cin>>m;
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    ll lcm = 1;
    for(int i=0;i<n;i++){

        lcm = lc(lcm,a[i]);
        if(lcm>5*m){
            cout<<0<<endl;
            return 0;
        }
    }
    for(int i=0;i<n;i++){
        if((lcm/a[i])%2==0){
            cout<<0<<endl;
                return 0;
        }
    }
    cout<<(m+lcm/2)/lcm<<endl;
    return 0;

}
