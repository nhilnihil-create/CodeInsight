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
ll a[N],s,res,f;
map<char,ll>mp;
vector<ll>v;
int main()
{
    Run();
    for(int i=1;i<=5;i++)
    {
        cin>>a[i];
        if(a[i]==0)
        {
            cout<<i;
            break;
        }
    }
}
