#include <bits/stdc++.h>
#define sz(v)   ((int)(v).size())
#define  all(v)    ((v).begin()),((v).end())
#define  allr(v)    ((v).rbegin()),((v).rend())
#define   pb         push_back
#define   mp         make_pair
#define   mt         make_tuple
#define   Y            imag()
#define   X            real()
#define    clr(v,d)      memset( v, d ,sizeof(v))
#define   angle(n)      atan2((n.imag()),(n.real()))
#define   vec(a,b)       ((b)-(a))
//#define   length(a)      hypot( (a.imag()),(a.real()) )
#define   normalize(a)      (a)/(length(a))
#define    dp(a,b)          (((conj(a))*(b)).real())
//#define    cp(a,b)          (((conj(a))*(b)).imag())
#define    lengthsqrt(a)       dp(a,a)
#define    rotate0( a,ang)    ((a)*exp( point(0,ang) ))
#define    rotateA(about,p,ang)   (rotate0(vec(about,p),ang)+about)
#define    reflection0(m,v)         (conj((v)/(m))*(m))
#define     reflectionA(m,v,p0)     (conj( (vec(p0,v))/(vec(p0,m)) ) * (vec(p0,m)) ) + p0
//#define     same(p1,p2)               ( dp(  vec(p1,p2),vec(p1,p2)) < eps )
#define     point                    complex<double>
#define outfile freopen("out.out", "w", stdout);
#define infile  freopen("in.in", "r", stdin);
#define PI acos(-1)
typedef  long long     ll ;
typedef  unsigned long long ull;
const double eps= (1e-9);
using namespace std;
int dcmp(double a,double b){   return fabs(a-b)<=eps ? 0: (a>b)? 1:-1  ;}
int getBit(int num, int idx) {return ((num >> idx) & 1) == 1;}
ll setBit1(ll num, int idx) {return num | (1ll<<idx);}
ll setBit0(ll num, int idx) {return num & ~(1ll<<idx);}
ll flipBit(int num, int idx) {return num ^ (1<<idx);}
void FS(){ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
const int N=509;
int ans[N][N];
void solve(vector<int> &v,int lv)
{
    if(sz(v)==1)
        return ;

    vector<int> a1,a2;
    for(int i=0;i<sz(v);i+=2)
    {
        a1.pb(v[i]);
        for(int j=1;j<sz(v);j+=2)
        {

            ans[v[i]][v[j]]=lv;
            ans[v[j]][v[i]]=lv;
        }
    }
    for(int j=1;j<sz(v);j+=2)
    {
         a2.pb(v[j]);
    }
    solve(a1,lv+1);
    solve(a2,lv+1);
}
int main()
{
    int n;
    cin>>n;
    vector<int> v;
    for(int i=1;i<=n;i++)
    {
        v.pb(i);
    }
    solve(v,1);
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}































