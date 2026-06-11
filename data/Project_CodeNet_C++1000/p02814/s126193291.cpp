/*!enjoy karo yaar!*/

//CF,CC,AtC,SPOJ: hp1999
//HE: hemant269
//HR: hemant2132

// just observed things...
// for a formal proof, refer this: https://codeforces.com/blog/entry/72955?#comment-572507

#include<bits/stdc++.h>
using namespace std;

#define     int             long long int
#define     fast()          ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define     all(x)          (x).begin(),(x).end()
#define     rz(x)           resize(x)
#define     mem(a,b)        memset(a,b,sizeof(a))
#define     sz(x)           ((int)(x.size()))
#define     pb              push_back
#define     pf              push_front
#define     pob             pop_back
#define     pof             pop_front
#define     ins             insert
#define     vi              vector<int>
#define     pii             pair<int,int>
#define     mii             map<int,int>
#define     F               first
#define     S               second
#define     makep           make_pair
#define     maket           make_tuple
#define     remax(a,b)      a=max(a,b)
#define     remin(a,b)      a=min(a,b)
#define     bitcount(x)     __builtin_popcountll(x)
#define     iceil(n,x)      (((n)-1)/(x)+1)
#define     gcd(a,b)        (__gcd((a),(b)))
#define     lcm(a,b)        ((a)*((b)/gcd((a),(b))))
#define     dbug(x)         cout<<#x<<": "<<(x)<<"\n"
#define     flush           fflush(stdout)
#define     show(x)         for(auto zz:x)cout<<zz<<" ";cout<<"\n";
#define     show2(x)        for(auto zz:x)cout<<zz.F<<" "<<zz.S<<"\n";

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

const ld pi=acos(-1);
const ll inf=1e18,M=1e9+7;
const int N=1;

int lsb(int x)
{
    int res=log2(x&-x);
    return res;
}

void solve()
{
    int n,m;
    cin>>n>>m;

    set<int> st;
    for(int i=0;i<n;++i)
    {
        int x;
        cin>>x;

        st.ins(x);
    }

    vi v;
    for(auto c:st)
        v.pb(c);
    n=sz(v);

    int arr[32]={0};
    for(int i=0;i<n;++i)
    {
        ++arr[lsb(v[i])];
    }

    for(int i=0;i<32;++i)       // checking, that every a_i has equal no. of 2s in it's prime factorization
                                // doing this might seem complicated at first sight
                                // but yeah, I observed a pattern and didn't go for a formal proof
    {
        if(arr[i])
        {
            if(arr[i]!=n)
            {
                cout<<0;
                return;
            }

            break;
        }
    }

    // this part is actually simple...
    int l=1;
    for(int i=0;i<n;++i)
    {
        l=lcm(l,v[i]);

        if(l/2>m)
        {
            cout<<0;
            return;
        }
    }

    int a=l/2;

    //cout<<pos<<" "<<a<<" "<<l<<"\n";

    m-=a;
    if(m<0)
        cout<<0;
    else
        cout<<m/l+1;
}

int32_t main()
{
    fast();

    int t=1;
    //cin>>t;
    for(int z=1;z<=t;++z)
    {
        solve();
        //cout<<"\n";
    }

    return 0;
}


