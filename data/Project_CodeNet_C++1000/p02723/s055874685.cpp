#include<bits/stdc++.h>
using namespace std;
typedef long long       ll;
#define MOD ((int)1e9+7)
#define N ((int)2e5+123)
void reads(string& x){ char kk[N]; scanf("%s",kk); x = kk;}

int ans, n;
string s;
void solve(){
    reads(s);
    n = (s[2] == s[3] && s[4] == s[5]);
    if(n)printf("Yes\n");
    else printf("No\n");
}

int main(){
    ios_base::sync_with_stdio(0);
    int t = 1; //scanf("%d",&t);
    for(int caso=1;caso<=t;caso++){
        solve();
    }
}