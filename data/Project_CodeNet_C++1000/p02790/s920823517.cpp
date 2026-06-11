
//Tanzim bin nasir
#include<bits/stdc++.h>
typedef long long ll;
#define ff first
#define ss second
using namespace std;
void fast()
{
ios::sync_with_stdio(false);
cin.tie(NULL); cout.tie(NULL);
}
ll gcd(ll a,ll b)
{
    if(b==0)
    return a;
    else
    gcd(b,a%b);
}
ll lcd(ll a,ll b)
{
    return (a*b)/gcd(a,b);
}
int main()
{
    int a,b;
    cin>>a>>b;
    if(a>b)
    {
        for(int i=0;i<a;i++)
        cout<<b;
    }
    else
    {
        for(int i=0;i<b;i++)
        cout<<a;
    }
    cout<<endl;
    return 0;
}

