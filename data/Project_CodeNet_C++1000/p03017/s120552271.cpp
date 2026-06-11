#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
    cin.tie(NULL); cout.tie(NULL);
    ios_base:: sync_with_stdio(false);
    ll n,a,b,c,d;cin>>n>>a>>b>>c>>d;
    string s;cin>>s;
    s='.'+s;
    for(ll i=a;i<c;i++)if(s[i]=='#' && s[i+1]=='#')return cout<<"No" , 0;
    for(ll i=b;i<d;i++)if(s[i]=='#' && s[i+1]=='#')return cout<<"No" , 0;
    if(c<d)return cout<<"Yes" , 0;
    for(ll i=b-1;i<d && i+1<n ;i++)if(s[i]=='.' && s[i+1]=='.' && s[i+2]=='.')return cout<<"Yes" , 0;
    cout<<"No";
}


