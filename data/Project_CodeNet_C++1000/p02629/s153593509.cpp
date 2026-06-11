#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define For(i,n) for(ll i=0; i<n; ++i)
#define all(v) (v).begin(), (v).end()
#define ff first
#define ss second
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define pb push_back
#define deb(x) cout<<"For debug : "<<x<<endl;
typedef long long ll;
#define ld long double

void solve()
{
    ll n;
    cin>>n;
    string s;
    map<int,char> mp;
    mp[0]='z';
    for(int i=0; i<25; i++)
    {
        char c = 'a'+i;
        mp[i+1] = c;
    }

    while(n>0)
    {
        int r=n%26;
        s+= mp[r];
        if(n%26==0) n--;
        n/=26;
    }
    reverse(s.begin(),s.end());
    cout<<s<<endl;
}

int main(){
    optimize();
    ll T=1;
    //cin>>T;
    while(T--)
    {
        solve();
    }
    return 0;
}
