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
    ll n,k;
    cin>>n;
    int a[n];
    map<int,int>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        m[a[i]]=i;

    }
    map<int,int>::iterator it;
    for(it=m.begin();it!=m.end();it++)
        cout<<it->ss+1<<" ";
    cout<<endl;



}




