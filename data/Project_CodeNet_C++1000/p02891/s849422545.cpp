#include <bits/stdc++.h>

#define int long long
#define counter(m)     for(int i=0;i<m;i++)
#define gcd            __gcd
#define endl           "\n"
#define pb             emplace_back
#define setbits(x)     __builtin_popcountll(x)
#define zrobits(x)     __builtin_ctzll(x)
#define mod            1000000007
#define mod2           998244353
#define maxe           *max_element
#define mine           *min_element
#define inf            1e18
#define deci(x, y)      fixed<<setprecision(y)<<x
#define w(t)           int t; cin>>t; while(t--)
#define nitin          ios_base::sync_with_stdio(false); cin.tie(NULL)
#define PI             3.141592653589793238
using namespace std;

int32_t main() {
    nitin;
    string s;
    int k;
    cin>>s>>k;
    int n=s.length();
    vector<int>v(26,0);
    for(auto c:s)
    {
        v[c-'a']++;
    }
    int cnt=0;
    for(auto c:v)
        if(c!=0)
            cnt++;
        if(cnt==1)
        {
            cout<<(n*k)/2<<endl;
        }
        else{



            char c=s[0];
            int pref=0;
            int i;
            for(i=0;i<n;i++)
            {
                if(s[i]==c)
                    pref++;
                else
                    break;
            }
            char d=s[n-1];
            int suff=0;
            int j;
            for(j=n-1;j>=0;j--)
            {
                if(s[j]==d)
                    suff++;
                else
                    break;
            }
            int ans=0;
            int temp=1;
            for(int q=i+1;q<=j;q++)
            {
                if(s[q]==s[q-1])
                    temp++;
                else
                {
                    ans+=(temp/2)*k;
                    temp=1;
                }
            }
            ans+=(temp/2)*k;
            if(c==d)
            {
                ans+=(pref)/2;
                ans+=suff/2;
                ans+=((pref+suff)/2)*(k-1);
            }
            else{
                ans+=(pref/2)*k;
                ans+=(suff/2)*k;
            }
            cout<<ans<<endl;
        }
    return 0;
}