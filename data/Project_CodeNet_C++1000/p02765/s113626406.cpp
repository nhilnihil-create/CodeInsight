#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void solution(){
    ll n,r;
    cin>>n>>r;
    if(n < 10)
        cout<<r+(100*(10-n))<<'\n';
    else
        cout<<r<<'\n';
}
int main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cerr.tie(0);
        /*ll t;
        cin>>t;
        while(t--)*/
        solution();
        return 0;
}