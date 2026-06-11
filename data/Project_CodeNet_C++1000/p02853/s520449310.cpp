//Radhe Radhe
#include<bits/stdc++.h>
#define godspeed  ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0);

#define ll long long
#define ld long double
#define fi first
#define se second
#define mp make_pair
#define rep1(i,a,b)    for(ll i=a; i<=b; i++)
#define repVect(i,n)    for(ll i=0; i<sum.size(); i++)
#define fixed cout.setf(ios::fixed);
#define Precise cout.precision(7);
#define yes cout<<"Yes"<<'\n'
#define no cout<<"No"<<'\n'
using namespace std;

int main()
{
    godspeed
    ll  i,j,k,l,x,y,z,a,b,bon,ans=0;
    string s;
    x=300000;
    y=200000 ;
    z=100000 ;
    bon=400000 ;
    cin>>a>>b;
    if(a==1)
        ans=x;
    if(a==2)
        ans=y;
    if(a==3)
        ans=z;
    if(b==1)
        ans+=x;
    if(b==2)
        ans+=y;
    if(b==3)
        ans+=z;
    if(a==1&&b==1)
        ans+=bon;
    cout<<ans<<endl;
    return 0;
}



