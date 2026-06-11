#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll n;
ll a[200006],b[200006];
int main(void){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
    }
    sort(a,a+n); sort(b,b+n);
    if(n%2==0){
        ll x=a[n/2-1]+a[n/2];
        ll y=b[n/2-1]+b[n/2];
        cout<<y-x+1<<endl;
    }else{
        cout<<b[n/2]-a[n/2]+1<<endl;
    }

}

