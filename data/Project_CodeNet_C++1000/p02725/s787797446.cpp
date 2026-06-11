#include<bits/stdc++.h>
using namespace std;
typedef long long       ll;
#define MOD ((int)1e9+7)
#define N ((int)2e5+123)
void reads(string& x){ char kk[N]; scanf("%s",kk); x = kk;}

int ans, n,k, mai = 0, ant, p;

void solve(){
    scanf("%d%d", &k,&n);
    scanf("%d",&ant);
    p = ant;
    for(int v,i=1;i<n;i++){
        scanf("%d",&v);
        mai = max(mai,v-ant);
        ant = v;
    }
    mai = max(mai,k-ant+p);
    printf("%d\n", k-mai);
}

int main(){
    ios_base::sync_with_stdio(0);
    int t = 1; //scanf("%d",&t);
    for(int caso=1;caso<=t;caso++){
        solve();
    }
}