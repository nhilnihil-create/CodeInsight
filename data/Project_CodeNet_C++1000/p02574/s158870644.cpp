#include<bits/stdc++.h>
#define fr(i,a,n) for(ll i=a;i<n;i++)
#define YES cout<<"YES"<<endl
#define all(v) v.begin(),v.end()
#define NO cout<<"NO"<<endl
#define pb(x) emplace_back(x)
#define fastio std::ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define vi vector<ll>
#define mi map<ll,ll>
#define pi pair<ll,ll>
#define what(x) cout<<#x<<" ="<<x<<endl;
using namespace std;
using ll =long long;


int main()
{
    fastio;
    ll n;
vector<ll>m(2000005);
    cin>>n;
    ll gcd=0;
    ll p=0;
    fr(i,0,n)
    {
        ll x;
        cin>>x;

        gcd=__gcd(gcd,x);
        bool prime=true;
        //if(x%2==0)if(m[2]>=1)p=1;else m[2]++;
        for(ll k=2;k*k<=x;k++)
        {
            if(x%k==0)
            {
            prime=false;
            m[k]++;
            //what(m[k]);
            if(k!=x/k) m[x/k]++;

            if(m[k]>1 || m[x/k]>1){ p=1; break;}

        }
        }
       // what(x);
            if(prime && x!=1)
            {
                m[x]++;
                if(m[x]>1){p=1;}
            }
    }

        if(p==0)cout<<"pairwise coprime"<<endl;
        else
        if(gcd==1)cout<<"setwise coprime"<<endl;

        else cout<<"not coprime"<<endl;


}


























