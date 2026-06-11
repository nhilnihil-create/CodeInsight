#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(30);
#define ll long long
#define ld long double
#define pi 3.14159265359
using namespace std;

int main()
{
    IOS;
    ld a,b;
    cin>>a>>b;
    b*=1000;
    a=(a*b)/1000;
    cout<<(ll)a;
    return 0;
}
