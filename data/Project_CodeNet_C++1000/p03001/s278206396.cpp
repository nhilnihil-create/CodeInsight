//om nama sivaya
#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define pb push_back
using namespace std;
void solve(){
    int w,h,x,y;
    cin>>w>>h>>x>>y;
    double a,b;
    a=w,b=h;
    cout<<a*b/2<<" ";
    if(x*2==a && y*2==b)
    cout<<"1";
    else
    cout<<"0";
    
}
int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    //cout.tie(NULL);
    int tt=1;
    //cin>>tt;
    while(tt--){
        solve();
    }
}
