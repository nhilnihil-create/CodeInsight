//om nama sivaya
#include<bits/stdc++.h>
#define ll long long
using namespace std;
void solve(){
    int n,m,c=0,co=0,x;
    cin>>n>>m;
    int a[n]={},w[n]={};
    string s;
    while(m--){
        cin>>x>>s;
        x--;
        if(!a[x]){
            if(s=="AC")
            a[x]++;
            else
            w[x]++;
        }
    }
    for(int i=0;i<n;i++){
        if(a[i]){
            c++;
            co+=w[i];
        }
    }
    cout<<c<<" "<<co;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
    //cin>>t;
    while(t--)
    solve();
}