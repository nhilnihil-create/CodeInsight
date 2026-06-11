#include<bits/stdc++.h>
using namespace std;
typedef long long       ll;
#define MOD ((int)1e9+7)
#define N ((int)2e5+123)
void reads(string& x){ char kk[N]; scanf("%s",kk); x = kk;}

int ans, n, m, v[N],sum,q;

void solve(){
    scanf("%d%d", &n,&m);
    for(int i=0;i<n;i++){
        scanf("%d",v+i);
        sum+=v[i];
    }
    sum = (sum+4*m-1)/(4*m);
    for(int i=0;i<n;i++){
        q+=(v[i]>=sum);
    }
    if(q>=m)printf("Yes\n");
    else printf("No\n");
}

int main(){
    ios_base::sync_with_stdio(0);
    int t = 1; //scanf("%d",&t);
    for(int caso=1;caso<=t;caso++){
        solve();
    }
}