#include <bits/stdc++.h>
#define sz(v)   ((int)(v).size())
#define  all(v)    ((v).begin()),((v).end())
#define  allr(v)    ((v).rbegin()),((v).rend())
#define   pb         push_back
#define   mp         make_pair
#define    clr(v,d)      memset( v, d ,sizeof(v))
typedef  long long     ll ;
typedef  unsigned long long ull;
const double EPS= (1e-9);
using namespace std;
int getBit(int num, int idx) {return ((num >> idx) & 1) == 1;}
int setBit1(int num, int idx) {return num | (1<<idx);}
ll setBit0(ll num, int idx) {return num & ~(1ll<<idx);}
ll flipBit(int num, int idx) {return num ^ (1<<idx);}
void GO(){ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
const int N=200000+9;
string s;
int vis[10009];
int main(){

    GO();
    int n,p;
    cin>>n>>p>>s;
    if(p==2||p==5){

        ll ans=0;
        for(int i=0;i<n;i++){
            if((s[i]-'0')%p==0){
                ans+=(i+1);
            }
        }
        cout<<ans<<"\n";
        return 0;
    }
    ll cur=0,ans=0,pp=1;
    vis[0]++;
    for(int i=n-1;i>=0;i--){
        int d=s[i]-'0';
        cur=(cur+d*pp)%p;
        ans+=vis[cur];
        vis[cur]++;
        pp*=10;
        pp%=p;
    }
    cout<<ans<<"\n";
}






















































































