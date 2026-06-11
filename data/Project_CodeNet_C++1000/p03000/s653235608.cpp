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
    int n,x;
    cin>>n>>x;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    int c=1,su=0;
    for(int i=0;i<n;i++){
        su+=a[i];
        if(su>x)
        break;
        c++;
    }
    cout<<c;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tt=1;
    //cin>>tt;
    while(tt--){
        solve();
    }
}
