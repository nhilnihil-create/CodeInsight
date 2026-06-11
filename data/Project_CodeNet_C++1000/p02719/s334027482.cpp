#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int  x,y;
    cin>>x>>y;
    long long int ans=min(x%y,y-(x%y));
    cout<<ans;

}
