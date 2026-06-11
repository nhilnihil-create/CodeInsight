#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //I don't care about anybody, and fuck ratings! I'll go to google!
    int n, k, x, ans = 0; cin>>n>>k;
    for(int i = 0; i<n; i++){
        cin>>x;
        if(x>=k) ans++;
    }
    cout<<ans<<"\n";
    return 0;
}
