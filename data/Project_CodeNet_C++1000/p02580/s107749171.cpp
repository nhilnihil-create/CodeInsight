using namespace std;
#include <bits/stdc++.h>
#define frr(i, r, l) for(int i = r; i >= l; --i)
#define fr(i, l, r) for(int i = l; i < r; ++i)
#define forit(it, type, var) for(type::iterator it = var.begin(); it != var.end(); it++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define MEMS(a,b) memset(a,b,sizeof(a))
#define fi first
#define se second
#define m_p make_pair
#define pb push_back
#define ll long long
#define ld long double
typedef pair<ll, ll> iPair; 
priority_queue< ll, vector <ll> , greater<ll>>pq1,pq2;
#define maxN 1000000000000000000
ll power(ll a,ll b){ll res=1;while(b>0){res*=a;b--;}return res;}
ll n,m,p,rw[300005],cl[300005],mx1=0,mx2=0,x,y,temp[300005];
vector<ll>w[300005],v1,v2;
int main()
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>n>>m>>p;

    fr(i,0,p)
    {
        cin>>x>>y;
        rw[x]++;
        if(rw[x]>=mx1)
        mx1=rw[x];

        cl[y]++;
        if(cl[y]>=mx2)
        mx2=cl[y];

        w[x].pb(y);
    }

    fr(i,1,n+1)
    {
        if(rw[i]==mx1)
        v1.pb(i);
    }
    fr(j,1,m+1)
    {
        if(cl[j]==mx2){
        v2.pb(j);}
    }
    ll fl=0;
    fr(i,0,v1.size())
    {
        ll st=v1[i];
        if(v2.size()>w[st].size())
        {
            fl=1;
            break;
        }
        fr(j,0,w[st].size())
        {
            temp[w[st][j]]++;
        }

        fr(j,0,v2.size())
        {
            if(temp[v2[j]]==0)
            {
                fl=1;
                break;
            }
        }
        fr(j,0,w[st].size())
        {
            temp[w[st][j]]=0;
        }
    }

    if(fl==1)
    {
        cout<<mx1+mx2<<endl;
    }
    else
    {
        cout<<mx1+mx2-1<<endl;
    }
    return 0;
}