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
typedef pair<ll,ll> p;
typedef unsigned long long int ull;
const ll MOD=998244353;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
const int MAXN=100000;
const int MAXE=100000;
const int MAXV=10000;
const ll INF=2e18;

int main(){
    int n,m;cin>>n>>m;
    vector<ii> c(n);
    for(int i=0;i<n;i++){
        int a,b;cin>>a>>b;
        c[i]=ii(a,b);
    } 
    sort(c.begin(),c.end());
    int i=0;
    int ans=0;
    priority_queue<int> que;
    for(int d=1;d<=m;d++){
        while(c[i].first<=d&&i<n){
            que.push(c[i].second);
            i++;
        }
        if(que.empty()) continue;
        int mx=que.top();que.pop();
        ans+=mx;
    }
    cout<<ans<<endl;
    return 0;
}