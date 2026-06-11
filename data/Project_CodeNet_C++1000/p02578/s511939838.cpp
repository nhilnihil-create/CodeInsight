#include <bits/stdc++.h>
using namespace std;
int main(){
    long n,ans=0;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++) cin >> a[i];
    int cur = a[0];
    for(int i=0;i<n;i++){
        if(a[i]<cur){
            ans += (cur-a[i]);
            a[i] = cur;
        } 
        cur = a[i];
    }
    cout << ans << endl;
}