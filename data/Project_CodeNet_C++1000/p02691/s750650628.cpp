#include<bits/stdc++.h>
using namespace std;


#define int long long
int a[200010];
signed main(){
    int n;cin>>n;
    int ans=0;
    map<int,int>mt;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        int t2=i+a[i];
        if(t2<=n&&t2>0){
            ++mt[t2];
        }
    }
    for(int i=1;i<=n;++i){
        int t1=i-a[i];
        if(t1>0){
            ans+=mt[t1];
        }
    }
    cout<<ans<<endl;

}
