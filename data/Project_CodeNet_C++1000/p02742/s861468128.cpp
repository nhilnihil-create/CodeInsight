#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll h,w;
    cin>>h>>w;
    ll ans=h*w;
    if(h== 1 ||w== 1)
        cout<< 1 <<endl;
    else
        cout<<(ans+1)/2;
    return 0;
}
