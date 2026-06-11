#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

vector<int>g[100003];
vector<int>v(100003);
queue<int>q;

int main()
{
    ll n,k;
    cin>>n>>k;

    ll a;
    ll c=0;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        if(a>=k)
        {
            c++;
        }
    }
    cout<<c<<endl;



}









