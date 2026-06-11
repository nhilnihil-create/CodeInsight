#include<bits/stdc++.h>
#define all(v) v.begin(),v.end()
using namespace std;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,h,nh=0,ans1=0,ans=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>h;
        if(nh>=h){
            ans1++;
            nh=h;
        }
        else{
            ans=max(ans,ans1);
            ans1=0;
            nh=h;
        }
    }
    ans=max(ans,ans1);
    cout<<ans<<endl;
    return(0);
}
