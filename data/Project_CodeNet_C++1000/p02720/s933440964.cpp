#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;
using namespace std;
int main(){
    int k;
    cin>>k;
    vector<int> ans;
    ans.push_back(1);
    ans.push_back(2);
    if(k<11){
        cout<<k<<endl;
        return 0;
    }
    int lun=2;
    rep(i,k-12){
        
        bool flag=true;
        for(int i=lun-1;i>0;i--){
            if(ans[i]==9)continue;
            if(ans[i-1]-ans[i]>-1){
                ans[i]++;
                for(int x=i+1;x<lun;x++) ans[x]=max(0,ans[x-1]-1);
                flag = false;
                break;
            }
        }
        if(flag){
            if(ans[0]==9){
                ans[0]=1;
                for(int a=1;a<lun;a++){
                    ans[a]=0;
                }
                ans.push_back(0);
                lun++;
            }
            else{
                ans[0]++;
                for(int a=1;a<lun;a++){
                    ans[a]=max(0,ans[a-1]-1);
                }
            }
        }
    // for(auto x:ans){
    //     cout<<x;
    // }
    // cout<<endl;
    }
    
    for(auto x:ans){
        cout<<x;
    }
    cout<<endl;
}
