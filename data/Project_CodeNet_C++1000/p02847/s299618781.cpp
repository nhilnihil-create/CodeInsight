#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pb push_back
const int maxn=2e5+10;
const int mod=998244353;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin>>s;
    if(s=="SUN")
        cout<<7<<'\n';
    else if(s=="MON")
    {
        cout<<6<<'\n';
    }
    else if(s=="TUE")
    {
        cout<<5<<'\n';
    }
    else if(s=="WED")
    {
        cout<<4<<'\n';
    }
    else if(s=="THU")
    {
        cout<<3<<'\n';
    }
    else if(s=="FRI")
    {
        cout<<2<<'\n';
    }
    else if(s=="SAT")
    {
        cout<<1<<'\n';
    }




}
