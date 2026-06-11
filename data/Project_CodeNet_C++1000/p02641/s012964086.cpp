#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int  main(){
    int x,n,ans=-1,cur=1e9;
    cin >> x >> n;
    map<int,int> p;
    rep(i,n){
        int a;
        cin >> a;
        p[a]++;
    }
    for(int i=0;i<=101;i++){
        if(p[i]>0) continue;
        if(abs(x-i)<cur){
            cur = abs(x-i);
            ans = i;
        }
    }
    cout << ans << endl;
}