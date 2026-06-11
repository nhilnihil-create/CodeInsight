//#pragma GCC optimize("03,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include<bits/stdc++.h>
typedef long long ll;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
#define pb           push_back
#define ff           first
#define ss           second
#define gcd(a, b)    __gcd(a, b)
#define lcm(a, b)    ((a)*((b)/gcd(a,b)))
#define all(v)       v.begin(),v.end()
#define lllim        2147483648
#define Pi           2*acos(0.0)
#define sci(n)	     scanf("%d",&n)
#define scii(n,m)    scanf("%d%d",&n,&m)
#define scl(n)       scanf("%lld",&n)
#define scll(n,m)    scanf("%lld%lld",&n,&m)
#define pii          pair<int,int>
#define pll 	     pair<ll,ll>
#define mem(a,b)     memset(a, b, sizeof(a))
#define fill_(a,b)   fill(a,a+n,b);
#define MOD          1000000007
#define fast_cin     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define filein       freopen("input.txt","r", stdin)
#define D(x)         cerr << __LINE__ << ": " << #x << " = " << (x) << '\n'
#define case		 int t,cas=1;cin>>t;while(t--)
#define rep(i,a,n)   for(int i=a;i<n;i++)
#define rev(i,n,a)   for(int i=n;i>=a;i--)

/*------------------------------Graph Moves----------------------------*/
//const int fx[]= {+1,-1,+0,+0};
//const int fy[]= {+0,+0,+1,-1};
//const int fx[]= {+0,+0,+1,-1,-1,+1,-1,+1};  // Kings Move
//const int fy[]= {-1,+1,+0,+0,+1,+1,-1,-1}; // Kings Move
//const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*---------------------------------------------------------------------*/

template<class T> void ckmin(T& a, const T& b) {
    a= b < a? b:a;
}
template<class T> void ckmax(T& a, const T& b) {
    a= b > a? b:a;
}



template<class T> void read(T& a) {
    std::cin>>a;
}
template<class T> void read(T& a,const int sidx, const int eidx) {
    for(int i=sidx; i<eidx; i++)
        std::cin>>a[i];
}



using namespace std;
using namespace __gnu_pbds;

const int maxn=100005;


vector<int>pr;
bool mark[maxn];

void si()
{
    mem(mark,0);
    for(int i=4; i<maxn; i+=2) mark[i]=1;
    for(int i=3; i*i<maxn; i+=2)
    {
        if(!mark[i])
            for(int j=i*i; j<maxn; j+=2*i)
                mark[j]=1;
    }

    pr.pb(2);
    for(int i=3; i<maxn; i+=2)
        if(!mark[i])
            pr.pb(i);
}

void solve()
{
    string s;
    ll k;
    read(s);
    read(k);

   // cout<<s<<" "<<s.size()<<endl;

    ll ans=0;

    ll prv=1;

    ll pos=0;
    ll cnt=-1;
    rep(i,1,s.size())
    {
        if(s[i]!=s[i-1])
        {
            if(cnt==-1)
            {
                cnt=i;

            }
            
            ans+=prv/2;
            prv=1;
        }
        else
        {
			prv++;
		}


    }
    ans+=prv/2;
    
    if(cnt==-1)
    {
		ll res=((ll)s.size() * k)/2;
		
		cout<<res<<endl;
		return;
	}
    
    ll res=ans*k;

    if(s[0]==s[s.size()-1])
    {
        ll cnt2=1;

        for(int i=s.size()-2; i>=pos; i--)
        {
            if(s[i]==s[i+1])
            {
                cnt2++;
            }
            else break;

        }
        
       // D(cnt);
       // D(cnt2);
        //D(res);
        
        res-=(cnt/2+cnt2/2-(cnt+cnt2)/2)*(k-1);
     

    }

	cout<<res<<endl;
}


int main()
{
    fast_cin;
    // si();

    //while(scanf("%d",&n)!=EOF)
//case
    {
        //cout<<""<<cas++<<""<<endl;
        solve();
    }

    return 0;
}
