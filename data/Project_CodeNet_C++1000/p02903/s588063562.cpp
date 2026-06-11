#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll h,w,a,b;cin>>h>>w>>a>>b;
    char arr[h][w];
    for(ll i=0;i<b;i++)for(ll j=0;j<a;j++)arr[i][j]='0';
    for(ll i=b;i<h;i++)for(ll j=0;j<a;j++)arr[i][j]='1';
    for(ll i=0;i<b;i++)for(ll j=a;j<w;j++)arr[i][j]='1';
    for(ll i=b;i<h;i++)for(ll j=a;j<w;j++)arr[i][j]='0';
    for(ll i=0;i<h;i++){
        for(ll j=0;j<w;j++)cout<<arr[i][j];
        cout<<"\n";
    }
}