#include<bits/stdc++.h>
using namespace std;
#define ios ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define endl '\n'
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
const ll mod=1e9+7;
bool sortbysec(const pair<int,int>&a,const pair<int,int>&b)
{
    return (a.second<b.second);
}
int main()
{
    int n,l;
    cin>>n>>l;
    vector<int>v(n+1);
    int f=0,sum=0;
    for(int i=1;i<=n;i++)
    {
        v[i]=l+i-1;
        if(!f&&v[i]>=0)
        {
            f=1;
            continue;
        }
        sum+=v[i];
    }
    if(!f)
    sum-=v[n];

    cout<<sum<<endl;







}


















































