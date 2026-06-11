#include<bits/stdc++.h>
using namespace std;
#define optimize() ios::sync_with_stdio(false);cin.tie(0);
#define endl '\n'
int main()
{
    //optimize();
    int a,b,c,k;
    cin>>a>>b>>c>>k;
    int ans=(min(k,a)*1);
    k-=a;
    if(k>0)
    {
        ans+=min(k,b)*0;
    }
    k-=b;
    if(k>0)
    {
        ans+=(min(k,c)*-1);
    }

    cout<<ans<<endl;


    return 0;
}
