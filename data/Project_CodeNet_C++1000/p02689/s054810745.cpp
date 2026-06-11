#include<bits/stdc++.h>
#define endl '\n'
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
#define REP(i,a,b) for(int i=a;i<b;i++)
#define maxx 100005

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

bool ok[maxx];
int main(){
    FASTIO;
    int n,m,a,b,cnt=0;
    cin>>n>>m;
    int h[n+1];
    REP(i,1,n+1) cin>>h[i];
    memset(ok,1,sizeof(ok));
    REP(i,0,m){
      cin>>a>>b;
      if(h[a]<=h[b]) ok[a]=0;
      if(h[b]<=h[a]) ok[b]=0;
    }
    REP(i,1,n+1) if(ok[i]) cnt++;
    cout<<cnt;
    return 0;
}
