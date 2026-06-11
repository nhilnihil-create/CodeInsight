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
bool sortbysec(const pair<int,int>&a,const pair<int,int>&b)
{
    return (a.second<b.second);
}
int main()
{
    ios;
    int n;
    cin>>n;
    int a[n+1],b[n],p=0;
    ll sum=0;
    for(int i=0;i<=n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
    {
        cin>>b[i];
        int t=min(b[i],a[i]);
        b[i]-=t;
        a[i]-=t;
        int k=min(b[i],a[i+1]);
        a[i+1]-=k;
        b[i]-=k;
        sum+=t+k;
    }
    cout<<sum<<endl;




}
//Alhamdulillah






