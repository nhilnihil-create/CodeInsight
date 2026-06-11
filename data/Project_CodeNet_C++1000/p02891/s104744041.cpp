#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
#include<string>
#include<bitset>
#include <sstream>
#include<queue>
#define rep(i,n) for(ll i=0;i<(n);++i)
using namespace std;
typedef long long ll;
typedef pair<int,int>P;

const int NMAX=1010101010;

int main()
{
    string s;
    cin>>s;
    ll k;
    cin>>k;
    ll n=s.length();
    ll count=0;
    ll fc=0,lc=0;
    int i=0;
    while(s[0]==s[i++] && i<=n && s[0]==s[n-1])fc++;
    i=n-1;
    while(s[n-1]==s[i--] && i>=0 && s[0]==s[n-1])lc++;
    if(fc==n)
    {
        cout<<k*fc/2;
        return 0; 
    }

    for(int k=fc;k<n-lc;k++)
    {
        if(s[k]==s[k-1])
        {
            count++;
            k++;
        }
    }
    ll ans=(fc/2)+lc/2+(k-1)*((fc+lc)/2)+k*count;
    cout<<ans;
}