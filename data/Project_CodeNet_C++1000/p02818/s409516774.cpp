#include<bits/stdc++.h>
using namespace std;
#define    For(i,n) for(int i=0;i<n;i++)
#define    fors(i,s) for(int i=0;i<s.size();i++)
#define    nl     "\n"
#define    End    return 0
#define    gt     greater<int>()
#define    ll     long long int

int main()
{
    ll a,b,n;
    cin>>a>>b>>n;
    ll x=b-(n-a);
    if(a<=n)
    {
        cout<<0<<" ";
        if(x>=0)cout<<x;else cout<<0;
    }
    else cout<<a-n<<" "<<b;
}
