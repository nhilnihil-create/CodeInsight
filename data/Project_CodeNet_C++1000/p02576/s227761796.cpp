#include <bits/stdc++.h>

using namespace std;
int n,x,t,ans1,ans2;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>x>>t;
    while(ans2 < n){
        ans2 += x;
        ans1 += t;
    }
    cout<<ans1<<'\n';
}
