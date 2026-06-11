#include<iostream>
#include<vector>
#include<map>
#include<cmath>
#include<string>
#include<bitset>
#include <sstream>
#define rep(i,n) for(ll i=0;i<(n);++i)
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin>>n;
    map<int,int> cc;
    for(int i=1;i<=n;i++)
    {
        if(i<10)
        {
            cc[i]++;
            continue;
        }

        if(i%10==0)
        {
            continue;
        }
        string num=to_string(i);
        int p=(*num.begin()-'0')*10+(*(num.end()-1)-'0');
        if(p/10==p%10)
        {
            cc[p/10]++;
        }
        else
        {
            cc[p]++;

        }
        
        
    }
    ll ans=0;
    for(auto v:cc)
    {
        //cout<<v.first<<endl;
        int a=v.first;
        if(a<10)
        {
            ans+=v.second*v.second;
        }
        else
        {
            int b=(a/10)+(a%10)*10;
            ans+=v.second*cc[b];
        }
        
    }
    cout<<ans<<endl;

}