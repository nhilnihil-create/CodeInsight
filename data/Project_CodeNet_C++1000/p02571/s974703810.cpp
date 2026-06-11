#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define vi vector<int>
#define vll vector<ll>
#define vvi vector < vi >
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mod 1000000007
#define inf 1000000000000000001;
#define all(c) c.begin(),c.end()
#define mp(x,y) make_pair(x,y)
#define mem(a,val) memset(a,val,sizeof(a))
#define eb emplace_back
#define pb push_back
#define f first
#define s second
using namespace std;


ll gcd(ll a, ll b)   //Function to find gcd of two numbers
{
    if (a == 0)
    return b;
    return gcd(b % a, a);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string str,t;
    cin>>str>>t;

    int ans = t.size();

    for(int start=0;start<=(str.size() - t.size());start++)
    {
        int diff=0;

        for(int i=0;i<t.size();i++)
        {
            if(t[i]!=str[start+i])
            diff++;
        }

        ans = min(ans,diff);
    }

    cout<<ans<<endl;

    
    return 0;
}