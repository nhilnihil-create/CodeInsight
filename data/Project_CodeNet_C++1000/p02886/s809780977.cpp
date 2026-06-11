#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout<<setprecision(15);

    //I don't care about anybody, and fuck ratings! I'll go to google!
    int n; cin>>n;
    vector<int> a(n);
    for(int i = 0; i<n; i++) cin>>a[i];
    int ans = 0;
    for(int i = 0; i<n; i++){
        for(int j = i+1; j<n; j++) ans += a[i]*a[j];
    }
    cout<<ans<<"\n";
    return 0;
}
