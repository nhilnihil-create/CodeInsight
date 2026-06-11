//Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>
using namespace std;
#define ios ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define endl '\n'
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
bool sortbysec(const pair<ll,ll>&a,const pair<ll,ll>&b)
{
    return (a.second<b.second);
}

int main()
{
    ios;
    int n;
    cin>>n;
    vector<int>l(n);
    for(int i=0;i<n;i++)
        cin>>l[i];
    sort(l.begin(),l.end());
    ll cnt=0;
    for(int i=n-1;i>=0;i--)
    {
        for(int j=i-1;j>=0;j--)
        {
            auto it=lower_bound(l.begin(),l.end(),l[i]+l[j]);
           ll ng=distance(it,l.end());
           cnt+=(n-1-i)-ng;
        }
    }
    cout<<cnt<<endl;



}









