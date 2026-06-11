#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define sd second
#define ft first
#define pr pair
#define vl vector<ll>
#define vs vector<string>
#define vmp vector<pair<ll,ll>>
#define en "\n"
#define lb lower_bound
#define ub upper_bound
#define vll vector<vector<ll>>
#define vmpl vector<vector<pair<ll,ll>>>
#define st size()
#define al(v) v.begin(),v.end()
#define cast static_cast<char>
#define ins insert
#define fata_fat ios_base::sync_with_stdio(false); cin.tie(NULL);
ll M=1e9+7,MAX=1e18,MIN=-1e18;
void bhaag()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}
int main()
{   
     bhaag(); fata_fat;
     ll l,r,d,c=0; cin>>l>>r>>d;
     for(ll i=l;i<=r;i++)
     {
        if(i%d==0)c++;
     }
     cout<<c;
     
}

 