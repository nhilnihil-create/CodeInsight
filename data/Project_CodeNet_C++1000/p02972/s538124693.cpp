#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;
using namespace std;

int main(){
    int n;cin>>n;
    vector<int> a(n+1);
    rep(i,n)cin>>a[i+1];
    int ans=0;
    vector<int> b(n+1,-1);
    for(int i=n;i>=1;i--){
        int x=(n/i)*i;
        int m=0;
        while(1){
            if(b[x]==-1){
                if(m%2!=a[x]){
                    b[x]=1;
                }
                else b[x]=0;
                break;
            }
            else if(b[x]==1){
                m++;
            }
            x-=i;
        }
        ans+=b[i];
        if((m+b[i])%2!=a[i]){
            cout<<"-1"<<endl;
            return 0;
        }
    }
    cout<<ans<<endl;
    rep(i,n){
        if(b[i+1]==1){
            cout<<i+1<<" ";
        }
    }
}