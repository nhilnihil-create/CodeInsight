#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define pb push_back
#define MOD 1000000007
int a[1000010];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n=0,c=1,res=0;string s;
    cin>>n;
    cin>>s;
    for(int i=0;i<(n-1);++i)
        a[i]=(int)abs(s[i]-s[i+1]);
    --n;
    int f[3];
    for(int i=0;i<n;++i)
        f[a[i]]+=1;
    if(f[1]==0)
    {
        c*=2;
        for(int i=0;i<n;++i)
            a[i]/=2;
    }
    for(int i=0;i<n;++i)
    {
        if(((n-1)&i)==i)
            res^=a[i];
    }
    cout<<(res&1)*c<<endl;
}
