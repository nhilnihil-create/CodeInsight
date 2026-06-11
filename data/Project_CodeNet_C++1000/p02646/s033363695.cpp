
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,n) for(ll i=a;i<n;i++)
#define rev(i,n,a) for(ll i=n-1;i>=a;i--)
#define f first
#define s second
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define vpii vector<pair<int,int>>
#define vpll vector<pll>
#define pll pair<ll,ll>
#define secreterror() ios_base::sync_with_stdio(false);cin.tie(NULL);

void solve(){

    ll a,v1;
    cin>>a>>v1;
    ll b,v2;
    cin>>b>>v2;

    ll time;
    cin>>time;

    ll fin=v1-v2;
    if(fin<=0){
        cout<<"NO"<<endl;
    }
    else
    {
        double take=abs(a-b)/double(fin);

        if(take<=time){
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
        
    }
    
    
}


int main()
{
    secreterror()
    // ll t;
    // cin>>t;
    //while(t--){
        solve();
        
    //}

}