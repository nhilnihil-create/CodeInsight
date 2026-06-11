#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define x first
#define y second

const int INF = 2e9 + 7;
const int MAXN = 2e5 + 7;

int f(pii p, int tp){
    if(tp==0)return p.x + p.y;
    else if(tp==1)return p.x - p.y;
    else if(tp==2)return -p.x + p.y;
    else return -p.x - p.y;
}

int main(){
    fastio; int n; cin>>n;
    int mx[4]; pii pmx[4];
    int mn[4]; pii pmn[4];
    for(int i=0; i<4; i++){
        mx[i] = -INF;
        mn[i] = INF;
    }
    for(int i=0; i<n; i++){
        int xi,yi; cin>>xi>>yi;
        pii p = {xi, yi};
        for(int j = 0; j<4; j++){
            if(f(p, j) > mx[j]){mx[j]=f(p,j); pmx[j]=p;}
            if(f(p, j) < mn[j]){mn[j]=f(p,j); pmn[j]=p;}
        }
    }
    int ans = -INF;
    for(int i=0; i<4; i++)ans = max(ans, mx[i] - mn[i]);
    cout<<ans<<endl;
}