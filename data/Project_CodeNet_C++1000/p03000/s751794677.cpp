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
    int n,x;
    cin>>n>>x;
    int l[n];
    ll cnt=1,s=0;
    for(int i=0;i<n;i++)
    {
        cin>>l[i];
        s+=l[i];
        if(s<=x)
            cnt++;

    }
    cout<<cnt<<endl;






}














































