#include<bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pb push_back
#define lop(i,a,b) for(ll i=a;i<b;i++)
using namespace std;

void func(){
    int n;
    cin>>n;
    vi a(n);
    lop(i,0,n)cin>>a[i];
    int xo=a[0];
    lop(i,1,n)xo^=a[i];
    lop(i,0,n)cout<<(xo^a[i])<<" ";
    cout<<endl;
}

int main(){
    fastio;
    int t=1;
    //cin>>t;
    while(t--){
        func();
    }
}