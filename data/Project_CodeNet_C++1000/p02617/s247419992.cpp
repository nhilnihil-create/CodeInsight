#include <bits/stdc++.h>
#define ll long long
#define ar array
#define AC ios_base::sync_with_stdio(0); cin.tie(NULL);
using namespace std;
const int M = 1e9+7;
const int N = 2*1e5;

int n;
ar<int,2> adj[N];

int main(){
    AC
    cin>>n;
    for(int i=0; i<n-1; i++){
        int a,b;
        cin>>a>>b;
        adj[i][0]=a;
        adj[i][1]=b;
    }

    ll ans = 0;
    for(int i=1; i<=n; i++){
        ans+=(ll)i*(n-i+1);
    }

    for(int i=0; i<n-1; i++){
        if(adj[i][0]>adj[i][1])
            swap(adj[i][0],adj[i][1]);
        ans-=(ll)adj[i][0]*(n-adj[i][1]+1);
    }
    cout<<ans<<endl;
}