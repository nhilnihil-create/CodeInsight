#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //good luck kittu!
    int n; cin>>n;
    vector<int> a(n+1);
    for(int i = 0; i<n; i++) cin>>a[i];

    ll ans = 0;
    map<int, int> m;
    for(int i = 0; i<n; i++){
        ans += m[i-a[i]];
        m[i+a[i]]++;
    }
    cout<<ans<<"\n";
    return 0;
}