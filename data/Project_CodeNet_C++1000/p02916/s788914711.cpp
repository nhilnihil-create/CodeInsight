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
   int a[n],b[n],c[n-1];
   for(int i=0;i<n;i++)
    cin>>a[i],--a[i];
   for(int i=0;i<n;i++)
    cin>>b[i];
   for(int i=0;i<n-1;i++)
    cin>>c[i];
    ll s=0;
    for(int i=0;i<n;i++)
    {
        s+=b[a[i]];
        if(a[i]==a[i-1]+1&&i>0)
            s+=c[a[i-1]];
    }
    cout<<s<<endl;

}
//Alhamdulillah















