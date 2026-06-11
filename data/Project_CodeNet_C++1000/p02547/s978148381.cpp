#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define mod 1000000007
#define ll long long int
#define pi 3.141592653589793238
const int N = 1e5 + 10;
int main(){
    FAST;
    ll t=1;
    // cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int cnt=0;
        bool f=false;
        while(n--)
        {
            int x,y;
            cin>>x>>y;
            if(x==y)
                cnt++;
            else
                cnt=0;
            if(cnt==3)
                f=true;
        }
        if(f)
            cout<<"Yes";
        else
            cout<<"No";
        }
    return 0;
}
