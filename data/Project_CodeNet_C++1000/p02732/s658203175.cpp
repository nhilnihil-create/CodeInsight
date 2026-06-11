#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); i++)
#define INF 999999999
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );

using llong = long long;
using namespace std;

int main(){
    llong n,a[200100],count[200100]={},sum[200100]={},all=0;
    cin >> n;
    rep(i,n){
        cin >> a[i];
        count[a[i]]++;
    }
    
    for(llong i=2;i<200010;i++) sum[i] += sum[i-1] + i-1;
    
    for(llong i=1;i<=n;i++){
        all += sum[count[i]];
    }
    
    for(llong i=0;i<n;i++){
        llong ans;
        ans = all - count[a[i]]+1;
        cout << ans << endl;
    }
}