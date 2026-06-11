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
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    ll dbc=(b/c);
    ll dbd=(b/d);
    ll k=((c*d)/__gcd(c,d));
    ll dbcd=(b/k);
    ll db=dbc+dbd-dbcd;
    ll dac=((a-1)/c);
    ll dad=((a-1)/d);
    ll dacd=((a-1)/k);
    ll da=dac+dad-dacd;

    ll ndcd=db-da;
    ll n=(b-a)+1;
    cout<<n-ndcd<<endl;








}



















































