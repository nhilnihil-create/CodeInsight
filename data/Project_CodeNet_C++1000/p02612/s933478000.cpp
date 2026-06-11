#include<bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n'
#define fo(i,n) for(int i=0;i<n;++i)
#define Fo(i,k,n) for(int i=k;i<n;++i)
typedef long long int lli;
int main(){
    FIO
    int price; cin>>price;
    if(price%1000==0) cout<<0<<endl;
    else cout<<1000-(price%1000)<<endl;
}
