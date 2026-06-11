#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxm=1e5+5;



signed main(){
    int a,b;cin>>a>>b;
    map<int,int>mark;
    for(int i=2;i*i<=a;i++){
        if(a%i==0){
            mark[i]=1;
            while(a%i==0)a/=i;
        }
    }
    if(a!=1)mark[a]=1;
    //
    int ans=0;
    for(int i=2;i*i<=b;i++){
        if(b%i==0){
            if(mark[i])ans++;
            while(b%i==0)b/=i;
        }
    }
    if(b!=1){
        if(mark[b])ans++;
    }
    //
    ans++;
    cout<<ans<<endl;
    return 0;
}
/*


*/
