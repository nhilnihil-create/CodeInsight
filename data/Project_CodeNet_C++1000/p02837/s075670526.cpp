#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;
using namespace std;
int main(){
    int n,ans=0;
    cin>>n;
    vector<vector<int>> a(n,vector<int>(n,2));
    rep(i,n){
        int m;
        cin>>m;
        rep(j,m) {
            int o,p;
            cin>>o>>p;
            o--;
            a[i][o]=p;
        }
    }
    for(int i=0;i<(1<<n);i++){
            bool flag=true;
            int p=0;
            vector<int> person(n,2);
        for(int j=0;j<n;j++){
            if((i>>j)&1){
                if(person[j]==0) {
                    flag=false;
                    break;
                }
                person[j]=1;
                p++;
                rep(k,n){
                    if(a[j][k]==1){
                        if(person[k]==0) {
                            flag=false;
                            break;
                        }
                        person[k]=1;
                    }
                    else if(a[j][k]==0){
                        if(person[k]==1) {
                            flag=false;
                            break;
                        }
                        person[k]=0;
                    }
                }
            }
            else{
                if(person[j]==1) {
                    flag=false;
                    break;
                }
                 person[j]=0;
                // rep(k,n){
                //     if(a[j][k]==1){
                //         if(person[k]==1) {
                //             flag=false;
                //             break;
                //         }
                //         person[k]=0;
                //     }
                //     else if(a[j][k]==0){
                //         if(person[k]==0) {
                //             flag=false;
                //             break;
                //         }
                //         person[k]=1;
                //     }
                // }
            }
        }
        if(flag)ans=max(ans,p);
    }
    cout<<ans<<endl;
}

