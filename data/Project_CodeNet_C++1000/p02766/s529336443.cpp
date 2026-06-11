#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void solution(){
    ll n,k;
    cin>>n>>k;
    ll counter =0;
    while(n > 0){
        counter++;
        n = n/k;
    }
    cout<<counter;
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