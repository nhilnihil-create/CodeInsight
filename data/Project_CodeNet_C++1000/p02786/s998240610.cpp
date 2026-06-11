//Code by Mukul Totla
#include<bits/stdc++.h>
using namespace std;
#define ll long long
void sublime(){  
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); }

int main()
{   
   // sublime();
    ll n;
    cin>>n;
    ll ans=0,i=0;

    while(n>0)
    {
        if(n==1)
        {
            n--;
            ans+=1LL<<i;
        }
        else if(n!=1)
        {
            n/=2;
            ans+=1LL<<i;
            i++;
        }
    }
    cout<<ans;
    
    return 0;
}