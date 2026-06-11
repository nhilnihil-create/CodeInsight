#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define dl double
#define PB push_back
#define MP make_pair
#define PPB pop_back
#define FI first
#define SE second
#define IN insert
#define ER erase
#define clean cout.flush()
#define PF push_front
#define PP pop
#define PH push
#define TP top
#define all(x) x.begin(),x.end()
#define REV reverse
#define IOS ios_base::sync_with_stdio(false);
#define inout freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);
//Here I have defined all the things.....have you any problem?

const ll mod=1e9+7;
const ll lim=1e6+10;
ll ara[lim];
ll b[lim];
ll f[lim];
ll m[100010];

//fasting input and output
void faster()
{
    IOS; cin.tie(NULL); cout.tie(NULL);
}

void Chocolate()
{
    ll a,b;
    cin>>a>>b;
    bool chex=true;
    for(int i=0;i<=1000000;i++)
    {
        ll k=i*(0.08);
        ll k1=i*(0.1);
        if(k==a && k1==b)
        {
            chex=true;
            cout<<i;
            return;
        }
    }
    cout<<-1;
}
int main()
{
    faster();
    //inout;
    //if you hack my code you are a bullshit
    /*ll t; cin>>t; while(t--)*/Chocolate();
    return 0;
}
//Remember, "FAILURE IS THE PILLAR OF SUCCESS"
