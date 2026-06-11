#include<bits/stdc++.h>
using namespace std ;
typedef long long ll;

#define cf ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define fox(i,n) for(int i=0;i<n;i++)
#define srtar(a,n) sort(a,a+n)
#define srtvec(v) sort(v.begin(),v.end())
#define fauto(x,t) for(auto x: t)
#define mem(n,x) memset(n, x, sizeof(n))
const ll mac=2e5;
bool cum[mac+10];
vector<ll>acn,prit;
void siv()
{
    ll i, j, k ;
    mem(cum,true);
    cum[0]=cum[1]=false;
    for(i=2; i<=mac; i++)
    {
        if(cum[i])
        {
            prit.push_back(i);
            for(j=i*i; j<=mac; j+=i)
            {
                cum[i]=false;
            }
        }
    }
}
map<ll,ll>mp;
void pf(ll n)
{
    ll i, j, p=0 ;
    for(i=0; i<prit.size(); i++)
    {
    //	 cout << p << "  p  ";
        p=prit[i];
       //  cout << p << "  p  ";
        if(p*p>n)
            break;
        if(n%p==0)
        {
            while(n%p==0)
            {
                n/=p;
            }
         //   cout << p << "  popk  ";
            mp[p]++;
        }
     //   cout << p << "  p  ";
    }
    if(n!=1)
        mp[n]++;
}
int main()
{
	 siv();
    ll t, m, g,n;
    cin >> n ;
    ll a[n];
    fox(i,n)
    {
        cin >> a[i];
        pf(a[i]);
        if(i==0)
            g=a[0];
        else
        {
            g=__gcd(g,a[i]);
        }
    }
    int y=1;
    for(auto x : mp)
    {
    //	cout << x.second << " " << x.first  << " , ";
        if (x.second != 1)
        {
        //	cout << x.second << " " << x.first ;
            y = 0;
            break;
        }
    }
    if(y)
        cout << "pairwise coprime" << endl;
    else if(g==1) cout <<"setwise coprime" << endl;
    else
        cout << "not coprime" << endl;
    return 0;
}