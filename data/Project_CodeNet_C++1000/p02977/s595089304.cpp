#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll n;cin>>n;
    if(__builtin_popcount(n)==1)return cout<<"No" , 0;
    cout<<"Yes\n"<<"2 "<<n+1<<"\n";
    for(ll x=2;x<n;x+=2){
        cout<<x<<" "<<x+1<<"\n";
        cout<<"1 "<<x+1<<"\n";
        cout<<"1 "<<x+n<<"\n";
        cout<<x+n<<" "<<x+n+1<<"\n";
    }

    ll k=0;while((1ll<<k)<n)k++;
    k--;

    if(n%2==0){
        cout<<n<<" "<<n+(1ll<<k)<<"\n";
        cout<<2*n<<" "<<(n-(1ll<<k))+1<<"\n";
    }
}