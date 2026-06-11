
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

    ll n,k;
    cin>>n>>k;

    vector<ll>pre(n+5,0);

    vector<ll>arr(n+1);

    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }

    ll logn=min((ll)41,(k));

    for(int k=0;k<logn;k++){
        for(int i=1;i<=n;i++){
            ll x=ceil(double(i)-0.5-double(arr[i]));
            ll y=floor(double(i)+0.5+double(arr[i]));

            x=max((ll)0,x);
            y=min(n,y);

            pre[x]++;
            pre[y+1]--;
        }

        for(int i=1;i<=n+3;i++){

            pre[i]=pre[i]+pre[i-1];

        }

        for(int i=1;i<=n;i++){
            arr[i]=pre[i];
        }

        for(int i=0;i<=n+3;i++){
            pre[i]=0;
        }


       
    }






    

    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
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