#include<bits/stdc++.h>
using namespace std;
#define lli long long int
# define rep(i,n) for(int i=0;i<n;i++)
void solve(){
    lli x,k,d;
    cin>>x>>k>>d;
    x = abs(x);

    lli straight = min(k,x/d);
    k-=straight;
    x-=straight*d;

    if(k%2==0)
    cout<<x<<endl;
    else{
        cout<<abs(x-d)<<endl;
    }
}
int main()
{
    int t;
    //cin>>t;
    t=1;
    while(t--){
        solve();
    }
}