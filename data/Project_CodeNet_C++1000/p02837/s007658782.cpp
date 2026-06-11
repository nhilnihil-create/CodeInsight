#include <bits/stdc++.h>
#define N 20 
using namespace std;
int nt[N],n,ans,l,r;
vector<pair<int,int> >test[N];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>nt[i];
        for(int j=1;j<=nt[i];j++){
            cin>>l>>r;
            test[i].push_back({l,r});
        }
    }
    for(int i=0;i<(1<<n);i++){
        int cnt=0,flag=0;
        for(int j=0;j<n;j++){
            if((i>>j)&1==1){
                cnt++;
                for(int k=0;k<nt[j+1];k++){
                    int l=test[j+1][k].first,r=test[j+1][k].second;
                    if((i>>(l-1)&1)!=r){
                        flag=true;
                        break;
                    }
                }
            }
            if(flag==true)break;
        }
        if(flag==false)ans=max(ans,cnt);
    }
    cout<<ans<<endl;
    return 0;
}