#include <bits/stdc++.h>

using namespace std;
using Graph = vector<vector<int>>;
using Grid= vector<vector<char>>;
using vin= vector<int>;
using ll=long long;
using vll= vector<ll>;
using vbl=vector<bool>;
using vch=vector<char>;
using pinin=pair<int ,int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rell(i,n) for (ll i=0; i< (ll)(n); i++)
#define sort(x) sort(x.begin(), x.end());
#define rese(x) reverse(x.begin(), x.end());
#define vnn(x,y,name) vector<vector<int>> name(x, vector<int>(y));

string yes="Yes",no="No";
ll mod=1e9+7;


int main() {
    ll n,k;
    cin>>n>>k;
    ll ans=0;
    for(ll i=k;i<=n+1;i++){
        ans+=1+(2*n-i+1)*i/2;
        
        ans-=i*(i-1)/2;
        ans%=mod;
       
    }
     cout<<ans<<endl;
    
}
