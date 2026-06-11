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
    double a,b;
    cin>>a>>b;
    int ans=0,k=1;
    while(k<b)
    {
        --k;
        k+=a;
        ans++;
    }
    cout<<ans<<endl;



}
//Alhamdulillah









