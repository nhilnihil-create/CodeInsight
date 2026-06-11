#include<bits/stdc++.h>
using namespace std;
typedef long long       ll;
#define MOD ((int)1e9+7)
#define N ((int)2e5+123)
void reads(string& x){ char kk[N]; scanf("%s",kk); x = kk;}

int ans, n;

void solve(){
    scanf("%d", &n);
    ans = 1000*(n/500);
    n%=500;
    ans += 5*(n/5);
    printf("%d\n", ans);
}

int main(){
    ios_base::sync_with_stdio(0);
    int t = 1; //scanf("%d",&t);
    for(int caso=1;caso<=t;caso++){
        solve();
    }
}