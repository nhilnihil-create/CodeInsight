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
    int n,k,q,a;
    cin>>n>>k>>q;
    map<int,int>m;
    for(int i=1;i<=n;i++)
     m[i]=k;
    int cnt=0;
    while(q--)
    {
        cin>>a;
        m[a]++;
        cnt++;

    }
    int c=0;
    map<int,int>::iterator it;
    for(it=m.begin();it!=m.end();it++)
    {
        if(it->ss-cnt>0)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }




}
//Alhamdulillah
























