#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(30);
#define ll long long
#define pi 3.14159265359
using namespace std;

int main()
{
    IOS;
    int x,y;
    cin>>x>>y;
    if (y%2!=0) return cout<<"No",0;
    y-=x*2;
    if (y<0 || y>x*2) return cout<<"No",0;
    cout<<"Yes";
    return 0;
}
