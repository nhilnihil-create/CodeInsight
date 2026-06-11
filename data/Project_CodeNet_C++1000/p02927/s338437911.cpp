#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
 
int main() {
    int m,d;
    cin >> m >> d;
    int ans=0;
    if(m==1||d<22) cout << 0 << endl;
    else{
        for(int i=2;i<=m;i++){
            for(int j=22;j<=d;j++){
                int j1=j%10;
                int j10=j/10;
                if(j1==1)continue;
                if(j1*j10==i) ans++;
            }
        }  
        cout << ans << endl;      
    }
}
