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
int main() {
        int n=D();
        int a[n];
        for(int i=0;i<n;i++)a[i]=D();
        sort(a,a+n);
        reverse(a,a+n);
        ll ans=a[0];
        int ind=1;
        for(int i=2;i<n;i++){
            if(i%2==1){
                ans+=1ll*a[ind];
                ind++;
            }else{
                ans+=1ll*a[ind];
            }
        }
        cout<<ans<<"\n";

}