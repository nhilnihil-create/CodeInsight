#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin >> n;
    int a[n][n-1];
    vector<bool> b(n,true);
    vector<int> c(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            cin >> a[i][j];
            a[i][j]--;
        }
    }
    int cnt=0,ans=0;
    while(cnt<n*(n-1)/2){
        vector<int> d(n);
        int sum=0;
        for(int i=0;i<n;i++){
            if(!b[i]||c[i]==n-1){
                continue;
            }
            int t=a[i][c[i]];
            if(a[t][c[t]]==i&&!d[i]){
                sum++;
                d[i]=true;
                d[t]=true;
            }
        }
        for(int i=0;i<n;i++){
            b[i]=d[i];
            if(d[i]){
                c[i]++;
            }
        }
        if(sum==0){
            cout << -1 << endl;
            return 0;
        }
        cnt+=sum;
        ans++;
    }
    cout << ans << endl;
}