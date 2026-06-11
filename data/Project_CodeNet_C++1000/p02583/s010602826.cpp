#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ll x;
    cin>>x;
    ll a[x];
    for(int i=0;i<x;i++) {
        cin>>a[i];
    }
    int ans = 0;
    for(int i=0;i<x;i++) {
        for(int j=i+1;j<x;j++) {
            for(int k=j+1;k<x;k++) {
                if(a[i] == a[k] || a[i] == a[j] || a[k] == a[j]) continue;
                ll v[3];
                v[0] =  a[i];
                v[1] = a[j];
                v[2] = a[k];
                sort(v, v+3);
                if(v[0] + v[1] > v[2])ans++;

            }
        }
    }
    cout<<ans<<endl;
}
