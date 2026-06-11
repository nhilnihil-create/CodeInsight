#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
typedef long long i64;
int main(){
    while (true) {
        int n;
        cin >> n;
        if(n==0) break;
        bool flags[2*n+1];
        repi(i,2,2*n+1) flags[i]=true;
        repi(i,2,2*n+1){
            if(flags[i]){
                for(int j=i*2;j<2*n+1;j+=i){
                    flags[j]=false;
                }
            }
        }
        int ans=0;
        repi(i,n+1,2*n+1) if(flags[i]) ans++;
        cout << ans << endl;
    }
    return 0;
}