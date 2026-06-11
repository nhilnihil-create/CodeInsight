#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, n) for(int i = 0; i < n; i++)
#define all(a) a.begin(), a.end()
#define P pair<int, int>
#define F first
#define S second
#define mod 1000000007
#define INF 900000000
signed main(){
    int m,d;cin>>m>>d;
    int ans=0;
    for(int i=1;i<=m;i++){
        for(int j=22;j<=d;j++){
            if(j%10>=2){
                if(j/10*(j%10)==i)ans++;
            }
        }
    }
    cout<<ans<<endl;
}
        