#include<bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pb push_back
#define lop(i,a,b) for(ll i=a;i<b;i++)
using namespace std;

void func(){
    int n,k;
    ll sum=0;
    cin>>n>>k;
    vi a(n);
    lop(i,0,n)cin>>a[i];
    sort(a.begin(),a.end());
    lop(i,0,k)sum+=a[i];
    cout<<sum<<endl;
}

int main(){
    fastio;
    int t=1;
    //cin>>t;
    while(t--){
        func();
    }
}