#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
using ii=pair<ll,ll>;
using vi=vector<ll>;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define INF (ll)1e18
#define all(x) (x).begin(),(x).end()
#define print(a); for(auto x:a)cout<<x<<" "; cout<<"\n";
#define mset(a); memset(a,0,sizeof(a));

const ll MOD=(ll)1e9+7;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	ll n;cin>>n;
    string s;cin>>s;
    ll cnt=0;
    for(int i=0;i<n;i++){
        while(s[i+1]==s[i]&&i<n-1)i++;
        cnt++;
    }
    cout<<cnt<<"\n";

}
