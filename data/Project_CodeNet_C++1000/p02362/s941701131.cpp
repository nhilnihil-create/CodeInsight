#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<cstdio>
#include<queue>
#include<deque>
#include<map>
#include<stack>
#include<set>
#include<utility>
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef unsigned long long int ull;
const ll MOD=1e9+7;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
const int MAXV=1000;
const int MAXE=2000;
const ll INF=1e18;

struct edge{
    int from,to;
    ll cost;
};

int n,m;
ll p;
vector<edge> es(MAXE);
vector<ll> d(MAXV,INF);

int main(){
    int v,e,r;cin>>v>>e>>r;
    for(int i=0;i<e;i++){
        int s,t,d;
        cin>>s>>t>>d;
        es[i]=edge{s,t,d};
    }
    d[r]=0;
    for(int i=0;i<v;i++){
        for(int j=0;j<e;j++){
            edge ed=es[j];
            if(d[ed.from]!=INF&&d[ed.to]>d[ed.from]+ed.cost){
                d[ed.to]=d[ed.from]+ed.cost;
                if(i==v-1){
                    cout<<"NEGATIVE CYCLE"<<endl;
                   return 0;
                }
            }
        }
    }
    for(int i=0;i<v;i++){
        if(d[i]==INF) cout<<"INF"<<endl;
        else cout<<d[i]<<endl;
    }
    return 0;
}
