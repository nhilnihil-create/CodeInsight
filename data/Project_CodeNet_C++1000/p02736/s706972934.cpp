#include<bits/stdc++.h>
#include<array>
#define nguyendz the_best


#define ll long long
#define ld long double
#define pb push_back
#define all(n) n.begin(),n.end()
#define eb emplace_back
#define endl "\n"
#define pll pair<ll,ll>
#define YES cout <<"YES"<<endl;
#define NO cout <<"NO"<<endl;
#define ff first
#define ss second
#define setpre(x) fixed<<setprecision(x)
//do not use "\n" in interactive problem
// ((x|y)-y) (x&(~y))
// __gcd(fibo(x),fibo(y)=fibo(__gcd(x,y))
//so luong tap hop gom d phan tu khac nhau dc tao tu k so phan biet la k mu d
// a+b=(a^b)+2*(a&b)
using namespace std;
const ll maxn=1e6+100;

const ll maxx=1e13;
const ll mod1=1000000007;
const ll mod2=998244353;
priority_queue<pll,vector<pll>,greater<pll>> q;
ll a[maxn];
ll gt[maxn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("test.txt","r",stdin);
    //   freopen("PHONGHAU.INP", "r", stdin);
    //  freopen("PHONGHAU.OUT", "w", stdout);
    ll n;
    cin>>n;
    bool y=false;
    for (int i=1; i<=n; i++)
    {

        char x;
        cin>>x ;
        a[i]=x-'0';
        a[i]--;
        if (a[i]==1)
            y=true;
    }
    gt[0]=0 ;
    for (int i=1; i<maxn; i++)
    {
        gt[i]=gt[i-1];
        ll cnt=0;
        ll j=i;
        while (j%2==0)
        {
            j/=2;
            cnt++;
        }
        gt[i]+=cnt;
    }

    ll dem=0;
    for (int i=1; i<=n; i++)
    {
        if (a[i]%2==0)
        {
            dem=(dem^0) ;
            continue;
        }
        ll t=gt[n-1];
        ll t1= gt[i-1];
        ll t2=gt[n-i];
        if (t==t1+t2)
        {
            dem=(dem^1);
        }
        else
        {
            dem=(dem^0) ;
        }
       // cout <<dem<<endl;
    }
  //  cout <<dem ;
    if (dem==1)
    {
        cout <<1;
    }
    else if (y)
    {
       //  cout <<34;
        cout <<0;
    }
    else
    {
        ll dem=0;
        for (int i=1; i<=n; i++)
        {
            a[i]/=2;
            if (a[i]%2==0)
            {
                dem=(dem^0) ;
                continue;
            }
            ll t=gt[n-1];
            ll t1= gt[i-1];
            ll t2=gt[n-i];
            if (t==t1+t2)
            {
                dem=(dem^1);
            }
            else
            {
                dem=(dem^0) ;
            }
        }
        if (dem==1)
        {
            cout <<2;
        }
        else
        {
            cout <<0;
        }
    }


}
