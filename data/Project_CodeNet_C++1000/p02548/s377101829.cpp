#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=1e9+7;
int main()
{
    int n;
    cin>>n;
    int res=0;
    for(int i=1; i<=n; i++)
    {
        int x=n/i;
        if(n%i==0)
            x--;
        res+=x;
    }
    cout<<res<<endl;
    return 0;
}
