#include <bits/stdc++.h>
using namespace std;

#define ll  long long
#define PII pair<ll,ll>
#define VI  vector<ll>
#define VB  vector<bool>
#define VC vector<char>
#define VVI vector<vector<ll>>
#define VVC vector<vector<char>>
#define VS  vector<string>
#define VP  vector<PII>
#define lf(i,a,b) for(ll i=a;i<=b;i++)
#define lr(i,a,b) for(ll i=a;i>=b;i--)
#define lfl(i,v) for(ll i=0;i<v.size();i++)
#define lrl(i,v) for(ll i=(ll)(v.size())-1;i>=0;i--)
#define chk2(a,b) cout<<"check :  "<<a<<" "<<b<<endl
#define chk3(a,b,c) cout<<"check :  "<<a<<" "<<b<<" "<<c<<endl
#define chk4(a,b,c,d) cout<<"check :  "<<a<<" "<<b<<" "<<c<<" "<<d<<endl
#define chk5(a,b,c,d,e) cout<<"check :  "<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<endl
#define l_b(v,k)  lower_bound(v.begin(),v.end(),k)-v.begin()
#define u_b(v,k)  upper_bound(v.begin(),v.end(),k)-v.begin()
#define mod 1000000007
#define sort(v) sort(v.begin(),v.end())
#define p_b push_back
#define p_f push_front
#define m_p make_pair
#define ff first
#define ss second
#define sz size()

int main()
{   int n,k;cin>>n>>k;
    if(k>((n-1)*(n-2))/2)
    {    cout<<-1<<endl;return 0;
    }
    int left=((n-1)*(n-2))/2-k;
    int m=n-1;
    VP edges;
    for(int i=2;i<=n;i++)
    {   PII p=m_p(1,i);
        edges.p_b(p);
    }
    lf(i,2,n)
        lf(j,i+1,n)
        {   if(left>0)
            {   PII p=m_p(i,j);
                edges.p_b(p);   
                left--;
                m++;
            }
            else
                break;
        }
    cout<<m<<endl;
    for(auto e:edges)
    {   cout<<e.ff<<" "<<e.ss<<endl;
    }
}