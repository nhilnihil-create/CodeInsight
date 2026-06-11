#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=2e3+1000;
ll a,b,c,k;
string s;
int main(){
    //freopen("in.txt","r",stdin);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>a>>b>>c>>k;
    ll ans=0;
    while(b<=a){
        b*=2;ans++;
    }while(c<=b){
        c*=2;ans++;
    }if(ans<=k) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}
