#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, k, d[1000], a[1000][1000], i, j, ans=0, cnt[1000]={0};
    cin >> n >> k;
    for(i=0;i<k;i++){
        cin >> d[i];
        for(j=0;j<d[i];j++){
            cin >> a[i][j];
            cnt[a[i][j]]++;
        }
    }
    for(i=1;i<=n;i++){
        if(cnt[i]==0) ans++;
    }
    cout << ans <<endl;
    return 0;
}

