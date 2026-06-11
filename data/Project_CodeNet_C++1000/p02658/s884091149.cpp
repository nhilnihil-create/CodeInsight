#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;

typedef long long ll;
const ll mod=1e9+7;
const int N=200000;

void Run()
{
     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}
//ll s[N],c[N];
ll h=1000000000000000000;
ll a[N],b[N];
vector<string>v;
map<string,int>mp;
int main()
{
    Run();
    unsigned long long x=1;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]==0)
        {
            cout<<0;
            return 0;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(x<=h/a[i])
        x*=a[i];
        else
        {
            cout<<-1;
            return 0;
        }
    }
        cout<<x;
}
