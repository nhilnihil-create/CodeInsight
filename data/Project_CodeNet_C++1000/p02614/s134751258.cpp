#include <bits/stdc++.h>
using namespace std ;
#define ll long long

inline int D(){
    int t ;
    scanf( "%d" , &t ) ;
    return t ;
}
inline ll LLD(){
    ll t ;
    scanf( "%lld" , &t ) ;
    return t ;
}
//const int INF = 0x3f3f3f3f;
//const int mod=1e9+7;
//const double pi=3.14159265359;
//###################################################################
char a[10][10];
int main() {
    int n=D(),m=D(),k=D();
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>a[i][j];

    ll ans=0;
    for(int maskr=0;maskr<(1<<n);maskr++){
        for(int maskc=0;maskc<(1<<m);maskc++){
            ll black=0;
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if((maskr&(1<<i))&&(maskc&(1<<j))&&a[i][j]=='#')
                        black++;
                }
            }
            if(black==k)ans++;
        }
    }
    cout<<ans;

}