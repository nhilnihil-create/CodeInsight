#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int b[(int) 1e6+7]={};
int  main(){
    int n,ans=0;
    cin >> n;
    int a[n];
    rep(i,n) cin >> a[i];
    for(int i=0;i<n;i++){
        if(b[a[i]]!=0){
            b[a[i]]=2;
            continue;
        } 
        
        for(int j=a[i];j<=1e6;j+=a[i]) b[j]++;
    }
    rep(i,n){
        if(b[a[i]]==1) ans++;
    }
    cout << ans << endl;
}