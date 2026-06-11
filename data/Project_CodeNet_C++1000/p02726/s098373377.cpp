#include<bits/stdc++.h>
using namespace std;
typedef long long       ll;
#define MOD ((int)1e9+7)
#define N ((int)2e3+123)
void reads(string& x){ char kk[N]; scanf("%s",kk); x = kk;}

int ans, n,x,y, v[N];

void solve(){
    scanf("%d%d%d", &n, &x, &y);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j)continue;
            ans = min(min(abs(i-j),abs(i-x)+abs(j-y)+1),abs(i-y)+abs(j-x)+1);
            v[ans]++;
            //printf("%d %d %d\n",i,j,ans);
        }
    }
    for(int i=1;i<n;i++)printf("%d\n",v[i]>>1);
}

int main(){
    ios_base::sync_with_stdio(0);
    int t = 1; //scanf("%d",&t);
    for(int caso=1;caso<=t;caso++){
        solve();
    }
}