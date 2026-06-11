#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(30);
#define ll long long
#define ld long double
#define pi 3.14159265359
using namespace std;

int main()
{
    IOS;
    ld n,a,s=1;
    cin>>n;
    while(n--){
        cin>>a;
        if(a==0) return cout<<0,0;
        s*=a;
    }
    if(s>(pow(10,18))) return cout<<-1,0;
    cout<<s;
    return 0;
}
