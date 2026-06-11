#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

vector<int>g[100003];
vector<int>v(100003);
queue<int>q;

int main()
{
    ll n;
    cin>>n;

    if(n%2==0)
    {
        cout<<0.5<<endl;
    }
    else
    {
        double a = (n/2)+1;
        double b = n;
        cout<<setprecision(7)<<fixed<<a/b<<endl;
    }


}








