#include <bits/stdc++.h>
 
using namespace std;

int main(){
    int n, x;
    cin >> n >> x;
    int l[101];
    for(int i=0;i<n;i++){
        cin >> l[i];
    }
    int d[101];
    int ans=0;
    d[0] = 0;
    for(int i=0; i<=n; i++){
        d[i+1] = d[i] + l[i];
    }
    for(int i=0; i<=n; i++){
        if(d[i] <= x){
            ans++;
        }
    }
    cout << ans << endl;
}