#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back 
#define mp make_pair
#define f first
#define s second
#define sz(x) ((int)x.size())
const ll maxint=2e18;
const ll minint =-2e18;
/*******\
(͡ ° ͜ʖ ͡ °) : Hello there, relax.
\*     */

int main(){
    int n;
    cin>>n;
    vector<ll> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int res = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[j]==a[i])continue;
            for(int k=j+1;k<n;k++){
                if(a[k]==a[j] || a[k]==a[i])continue;
                if(a[i]+a[j] > a[k] && a[k]+a[j]>a[i] && a[k]+a[i] > a[j])res++;
            }
        }
    }
    cout<<res<<'\n';
    return 0;
}