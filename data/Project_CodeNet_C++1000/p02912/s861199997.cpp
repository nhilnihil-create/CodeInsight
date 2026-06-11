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
    int n,m,k;
    priority_queue<int>pq;
    cin>>n>>m;
    while(n--)
    {
        cin>>k;
        pq.push(k);
    }
    while(m--)
    {
        int l=pq.top();
        pq.pop();
        int t=l/2;
        pq.push(t);
    }
    ll sum=0;
    while(!pq.empty())
    {
        sum+=pq.top();
        pq.pop();
    }
    cout<<sum<<endl;




}
//Alhamdulillah























