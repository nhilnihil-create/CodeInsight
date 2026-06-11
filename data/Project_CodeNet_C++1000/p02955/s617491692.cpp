#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    vector<int> r(n);
    for(int i=0; i<n; i++) cin >> a[i];
    int sum=0;
    for(int i=0; i<n; i++) sum += a[i];
    
    int d[100000];
    int x=0;
    d[x]=sum;
    x++;
    int p=2;
    while(p*p <= sum){
        if(sum%p == 0){
            d[x] = p;
            x++;
            d[x] = sum/p;
            x++;
        }
        p++;
    }
    int ans=1;
    for(int j=0; j<x; j++){
        p=d[j];
        for(int i=0; i<n; i++) r[i]=a[i]%p;
        sort(r.begin(), r.end());
        int y=0;
        for(int i=0; i<n; i++) y += r[i];
        int z = 0;
        for(int i=n-y/p; i<n; i++) z += (p-r[i]);
        if(z <= k) ans = max(ans,p);
    }
    cout << ans << endl;


}