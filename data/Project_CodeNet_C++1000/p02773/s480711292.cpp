
#include<bits/stdc++.h>
#define ll long long
#define vll vector<ll>
#define pb push_back
#define eb emplace_back
#define sll set<ll>
#define ins insert
#define rep(i,n) for(int i=0;i<n;i++)
#define vpp vector<pair<int,int>>
#define mp make_pair
#define ft first
#define sc second
#define gp " ";
#define MAX 9999999
#define MOD 1000000007
#define mnn(v2) *min_element(v2.begin(),v2.end());
#define mxx(v2) *max_element(v2.begin(),v2.end());
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t=1;
    //cin>>t;
    while(t--)
    {
        ll n,i,j,k,c=0,mx=0;
        cin>>n;
        string s;
        map<string,ll>m;
        for(i=0; i<n; i++)
        {
            cin>>s;
            m[s]++;
        }

        map<string,ll>:: iterator itr;
        for (itr = m.begin(); itr != m.end(); ++itr)
        {
               if(itr->second>=mx)
                    mx=itr->second;

        }
        for (itr = m.begin(); itr != m.end(); ++itr)
        {
               if(itr->second==mx)
                   cout<<itr->first<<endl;

        }

    }
}
