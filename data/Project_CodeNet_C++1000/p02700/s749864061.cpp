#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 5;
ll lcm(ll a,ll b){return a*b/__gcd(a,b);}
int main()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    while(a>0&&c>0)
    {
        c-=b;
        if(c<=0)break;
        a-=d;
    }
    if(a>0)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
