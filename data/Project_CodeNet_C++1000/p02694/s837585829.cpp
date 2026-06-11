#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll x, p = 100, ans = 0;
    cin>>x;
    while(p < x){
        p += p/100;
        ans++;
    }
    cout<<ans<<endl;
    return 0;
}
