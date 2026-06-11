#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int n,m;
    cin >> n >> m;
    int ans = n;
    int sum = 0;
    rep(i,m){
        int a;
        cin >> a;
        sum += a;
    }
    if(sum > n) printf("-1\n");
    else printf("%d\n",ans-sum);
    return 0;
}