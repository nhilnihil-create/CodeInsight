#include<bits/stdc++.h>
#include<string.h>
#define pb push_back
#define all(v) v.begin(),v.end()
#define see(x) cout<<#x<<" : "<<(x)<<endl;
#define ya cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define ff first
#define sc second
typedef long long ll;
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    //freopen("test.txt","r",stdin);
    ll a,b,v,w,i,j,t;
    cin>>a>>v>>b>>w>>t;
    i=b+(w*t);
    j=a+(t*v);
    if(a<b)
    {
        if(j>=i)
        {
            ya
            return 0;
        }
    }
    else
    {
        i=b-(w*t);
        j=a-(t*v);
        if(j<=i)
        {
            ya
            return 0;
        }
    }
    no
    return 0;
}
