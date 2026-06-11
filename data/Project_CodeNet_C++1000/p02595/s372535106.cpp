#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false);cin.tie(0);
#define ADD +
#define SUBTRACT -
#define MULTIPLY *
#define DIVIDE /
#define MOD %
#define INCREMENT(x) ++x
#define DECREMENT(x) --x
#define in(a,b) cin>>a>>b;
#define out(a,b) cout<<a<<endl<<b<<endl;
#define scan(a) scanf("%d",&a);
#define print(a) printf("%d\n",a);
#define scanii(a,b) scanf("%d %d",&a,&b);
#define printii(a,b) printf("%d\n%d\n",a,b);
#define scaniii(a,b,c) scanf("%d %d %d",&a,&b,&c);
#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define ll long long
#define ull unsigned long long
#define sll signed long long
#define f1(i,a) for(int i=0;i<a;++i)
#define f2(i,a) for(int i=a-1;i>=0;--i)
#define pi acos(-1)
#define mod 1000000007
#define TRUE 1
#define FALSE 0
#define ZERO 0
#define MP make_pair
#define F first
#define S second

#define END puts("");
#define elif else if
typedef ll int lli;
typedef sll int slli;
typedef ull int ulli;
const int sz=10000;
using namespace std;

int clue();
int result();
void show();
bool check();

int main() {
    clue();
    return 0;
}
int clue() {
    
    lli n,d;
    cin>>n>>d;
    // multimap<lli,lli>m;
    // multimap<lli,lli>::iterator it;
    // list<pair<lli,lli> >m;
    // list<pair<lli,lli> >::iterator it;

    lli count=0;
    while(n-->0) {
        lli x,y;
        cin>>x>>y;
        lli p=x*x;
        lli q=y*y;
        lli pp=p+q;
        double c=sqrt(pp);
        if(c<=d)++count;
        // m.insert(MP(x,y));
        // m.pub(MP(x,y));
    }
    // for(it=m.begin();it!=m.end();++it) {
    //     lli x,y;
    //     x=it->first MULTIPLY it->first;
    //     y=it->second MULTIPLY it->second;

    //     lli p=x+y;
    //     double dd=sqrt(p);
    //     if(dd<=d)++count;
    // }
    // for(it=m.begin();it!=m.end();++it) {
        // cout<<it->first<<" "<<it->second<<endl;
    // }

    cout<<count<<endl;
    return 0;
}