#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;
using namespace std;
 
int main(){
    int n;cin>>n;
    ll ans=0;
    for(int i=1;i<=n;i++){
        int a=log10(i)+1;
        if(a%2)ans++;
    }
    cout<<ans<<endl;
}
