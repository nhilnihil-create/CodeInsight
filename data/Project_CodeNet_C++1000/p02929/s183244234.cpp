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
const int N=200009,mod=1e9+7;
string st;
char B[N];
int n;
void fin()
{
    cout<<"0"<<endl;
    exit(0);
}
int main()
{

    cin>>n>>st;
    if(st[0]=='W')
    {
        fin();
    }

    B[0]='L';
    for(int i=1;i<n*2;i++)
    {
        if(st[i]==st[i-1])
        {
            if(B[i-1]=='L')
                B[i]='R';
            else
                B[i]='L';
        }
        else
        {
            B[i]=B[i-1];
        }
    }
    ll ans=1,cnt=0;
    for(int i=0;i<n+n;i++)
    {
        if(B[i]=='L')
        {
            cnt++;
        }
        else
        {
            ans=(ans*cnt)%mod;
            cnt--;
        }

        if(cnt>n||cnt<0)
            fin();
    }

    if(cnt!=0)
        fin();
    ll F=1;
    for(int i=2;i<=n;i++)
        F=(F*i)%mod;
    cout<<(ans*F)%mod<<endl;
}


















