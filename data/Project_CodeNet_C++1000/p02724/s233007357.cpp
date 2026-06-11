#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int x=n/500;
    int y=(n-x*500)/5;
    int ans=1000*x+5*y;
    cout<<ans<<endl;
    return 0;
}