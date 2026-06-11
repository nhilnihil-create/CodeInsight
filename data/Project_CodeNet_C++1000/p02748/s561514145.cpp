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
#define yes cout<<"Yes"<<'\n';
#define no cout<<"No"<<'\n';
using namespace std;

int main()
{
    godspeed
    ll  t,i,x,y,c,j,k,n,a,b,m,minia=INT_MAX,minib=INT_MAX;
    string s;
    vector<ll>price;
    cin>>a>>b>>m;
    ll ar[a],br[b];
    for(i=0; i<a; i++)
    {
        cin>>ar[i];
        minia=min(ar[i],minia);
    }
    for(i=0; i<b; i++)
    {
        cin>>br[i];
        minib=min(br[i],minib);
    }
    ll emniPai=minia+minib;
    while(m--)
    {
        cin>>x>>y>>c;
        price.push_back(ar[x-1]+br[y-1]-c);
    }

    cout<<min(emniPai,*min_element(price.begin(),price.end()))<<endl;
    return 0;
}



