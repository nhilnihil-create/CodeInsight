#include<bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define mod 1000000007
using namespace std;
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ull num=0;
    int k;
    cin>>k;
    if(k%2==0)
    {
        cout<<-1;
        return 0;
    }
    int i;
    for(i=1;i<1e6;i++)
    {
        num%=k;
        num=(num*10);
        num+=7;
        if(num%k==0)
        {
            cout<<i;
            return 0;
        }
    }    
    cout<<-1;
    return 0;
}