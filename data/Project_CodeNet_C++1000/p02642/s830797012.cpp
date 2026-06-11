#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define fi first
#define se second
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define debug(a) cout << #a << " = " << a << " ";
#define endl "\n"
#define MOD (int) 1e9+7
#define inf (int) (1e18)

void solve(){
    long int n;
    cin>>n;
    long int x[n];
    for(long int i=0;i<n;i++){
        cin>>x[i];
    }
    sort(x,x+n);
    vector<int> v(x[n-1]+10,0);
    long int ans=0;
    for(long int i=0;i<n;i++){
        if(i>0 && x[i]==x[i-1]){
            v[x[i]]=1;
            continue;
        }
        int j=2;
        while(x[i]*j<x[n-1]+10){
            v[x[i]*j]=1;
            j++;
        }
    }
    for(int i=0;i<n;i++){
        if(v[x[i]]==0)
            ans++;
    }
    cout<<ans<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long int t=1;
    // cin >> t;
    for(long int tt=1;tt<=t;tt++){
        solve();
    }
    return 0;
}