#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x ,n) for(int i = x; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main(){
    int n,ans=0;
    cin >> n;
    int d[n];
    rep(i,n)cin >> d[i];
    rep(i,n-1){
        rep2(j,i+1,n){
            ans+=d[i]*d[j];
        }
    }
    
    
    cout << ans;
    
	return 0;
}