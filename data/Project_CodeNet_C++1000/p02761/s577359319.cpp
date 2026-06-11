#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<pair<int,int>> vpii;

const double PI=acos(-1.0);

int N,M; vpii P;
void input()
{
    cin>>N>>M;
    for(int i=0;i<M;++i){
        int a,b; cin>>a>>b; 
        P.emplace_back(make_pair(a,b));
    }
    return;
}

void solve()
{
    sort(P.begin(),P.end());
    vi tmp(N,-1);
    for(int i=0;i<M;++i){
        if(tmp[P[i].first-1]==-1) tmp[P[i].first-1]=P[i].second;
        else{
            if(tmp[P[i].first-1]!=P[i].second){
                cout<<"-1"<<endl;
                return;
            }
        }
    }
    int ans=0;
    if(N>1) {
        if(tmp[0]==0){
            cout<<"-1"<<endl; return;
        }
        else if(tmp[0]==-1) tmp[0]=1;
    }
    for(int i=0;i<N;++i){
        if(tmp[i]==-1) tmp[i]=0;
    }
    for(int i=0;i<N;++i) ans=ans*10+tmp[i];
    cout<<ans<<endl;
    return;
}

int main()
{
    cin.tie();
    ios::sync_with_stdio(false);
    input();
    solve();
    return 0;
}