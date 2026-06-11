#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 1e9L+7;
int n;
vector<vector<ll>> inp;
vector<vector<ll>> dp;

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    /*#ifndef ONLINE_JUDGE
    #endif*/
    
    int t=1;
    //cin>>t;
    while(t--)
    {
        /*inp.assign(r+2,vector<ll> (c+2,0));
        dp.assign(r+2,vector<vector<ll>> (c+2,vector<ll> (4,-1)));
        */
        ll k;
        cin>>n>>k;
        ll p[n],c[n];
        for(int i=0;i<n;i++)
        {
            cin>>p[i];
            p[i]--;
        }
        for(int i=0;i<n;i++)
        {
            cin>>c[i];
        }
        ll ans=INT32_MIN;
        
        for(int i=0;i<n;i++)
        {
            ll precnt=0;
            ll cf=0;
            int s = i;
            do
            {
                precnt++;
                cf += c[s];

                s = p[s];
            } while (s != i);

            int cnt = 1;
            ll sum = 0;
            s  = i;
            do
            {
                s = p[s];
                sum += c[s];

                ans  = max(ans,max((k-cnt)/precnt*cf,0LL) + sum);

                cnt++;    
            } while (cnt<=min(k,precnt));
            
            
        }

        cout<<ans<<endl;
    }
}
