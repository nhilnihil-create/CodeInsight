#include<bits/stdc++.h>
#define endl "\n" 
using namespace std;
#define debug(x) cout<<"The value of "<<#x<<" is "<<x<<endl;
typedef long long ll;
typedef unsigned long long ull;

int main()
{
    cin.sync_with_stdio(0); cin.tie(0); 
    int x;
    cin>>x;
    int ans=0;
    int full=x/500;
    ans+=full*1000;
    x-=full*500;
    ans+=(x/5)*5;
    cout<<ans<<endl; 
}
