#include <bits/stdc++.h>
#define sz(v)   ((int)(v).size())
#define  all(v)    ((v).begin()),((v).end())
#define  allr(v)    ((v).rbegin()),((v).rend())
#define   pb         push_back
#define   mp         make_pair
#define    clr(v,d)      memset( v, d ,sizeof(v))
#define     PI                       acos(-1)
typedef  long long     ll ;
typedef  unsigned long long ull;
const double eps= (1e-9);
using namespace std;
int dcmp(long double a,long double b){   return fabsl(a-b)<=eps ? 0: (a>b)? 1:-1  ;}
int getBit(ll num, int idx) {return ((num >> idx) & 1ll) == 1;}
int setBit1(int num, int idx) {return num | (1<<idx);}
ll setBit0(ll num, int idx) {return num & ~(1ll<<idx);}
ll flipBit(ll num, int idx) {return num ^ (1ll<<idx);}
void GO(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
int countNumBit1(int mask) {int ret=0; while (mask) 	{mask &= (mask-1);++ret;	}return ret;}
const int N=300000+5,mod=1e9+7;
int Cnt_r[N],Cnt_c[N],r[N],c[N],vis[N];
vector<int> v[N];
int main(){
    GO();
    int n,m;
    cin>>n>>m;
    int cnt;
    cin>>cnt;
    int mx=0;
    for(int i=0;i<cnt;i++){
        cin>>r[i]>>c[i];
        Cnt_r[r[i]]++;
        Cnt_c[c[i]]++;
        mx=max(mx,Cnt_c[c[i]]);
        v[c[i]].pb(r[i]);
    }
    int tot=0;
    for(int i=1;i<=300000;i++){
        if(Cnt_c[i]==mx){

            for(int j=0;j<sz(v[i]);j++){
                int rw=v[i][j];
                vis[rw]++;
            }
            tot++;
        }
    }
    int res=0;
    for(int i=1;i<=300000;i++){
        int ans= Cnt_r[i]+(vis[i]!=tot?mx:mx-1);
        res=max(res,ans);
    }
    cout<<res<<"\n";

}























































































































































































