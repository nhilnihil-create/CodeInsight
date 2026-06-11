#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int a,b;
    cin>>a>>b;
    if(a==1 || b==1)
    {
        cout<<1<<"\n";
        return 0;
    }
    long long int ans = (a*b)/2;
    if((a*b)%2!=0)
    ans++;
    cout<<ans<<"\n";
    
}