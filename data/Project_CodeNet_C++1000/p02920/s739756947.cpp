#include <bits/stdc++.h>
 
using namespace std;
 
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define fileio freopen("in.in", "r", stdin),freopen("out.out", "w", stdout);
#define ll long long int
#define FF first
#define SS second
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<long long int,long long int>
#define sd(x) scanf("%d",&x)
#define slld(x) scanf("%lld",&x)
#define pd(x) printf("%d\n",x)
#define plld(x) printf("%lld\n",x)
#define pss printf
#define MOD 1000000007
#define INF 1e18
#define eps 0.00001
#define endl '\n'
#define debug(n1) cout<<n1<<endl

int n,a[1000005];
multiset<int>fre,cur,tmp;

int main()
{
    SPEED;

    cin>>n;
    for(int i=1;i<=(1<<n);i++)
    {
        cin>>a[i];
        fre.insert(a[i]);
    }

    cur.insert(*fre.rbegin());
    fre.erase(fre.find(*fre.rbegin()));
    for(int h=0;h<n;h++)
    {
        tmp.clear();
        for(auto j:cur)
        {
            auto h=fre.lower_bound(j);
            if(h==fre.begin())
                return cout<<"No"<<endl,0;
            h--;
            tmp.insert(*h);
            fre.erase(h);
        }
        for(auto j:tmp)
            cur.insert(j);
    }

    cout<<"Yes"<<endl;
    return 0;
}