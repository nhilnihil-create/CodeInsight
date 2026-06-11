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
    int n,c=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int k=i,nd=0;
        while(k!=0)
        {
            k/=10;
            nd++;
        }
        if(nd%2)
            c++;
    }
    cout<<c<<endl;



}
//Alhamdulillah
















