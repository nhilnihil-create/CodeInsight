#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
#define ff first
#define ss second
#define p pair<ll,ll>
#define pb push_back
#define endl '\n'
#define w(t) ll test;cin>>test;while(test--)
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(0);
#define iof  freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define pi acos(-1)
const int mxn=1e9+5;
int main()
{
    fast;
    ll n;
    cin>>n;
    map<int,char>mp;
    char c='a';
    for(int i=1;i<=26;i++)
    {
        mp[i]=c;
        c++;
    }
    vector<char>ans;
   // if(n%2==0)n--;
    while(n)
    {

        //cout<<n<<" ";
        int tmp=n%26;
       if(!tmp)tmp=26;
        n--;

        ans.pb(mp[tmp]);
        n/=26;
       // cout<<tmp<<" "<<n<<endl;

    }

   // ans.pb(mp[n]);
    reverse(ans.begin(),ans.end());
    for(auto i:ans)
    {
        cout<<i;
    }
    cout<<endl;
}


