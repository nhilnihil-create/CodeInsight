#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,ans=0,tmp=1;
    cin >> n;
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        if(a!=tmp)ans++;
        else tmp++;
    }
    if(ans==n)cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}