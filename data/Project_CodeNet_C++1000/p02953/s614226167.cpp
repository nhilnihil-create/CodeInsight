#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> h(n);
    vector<bool> dp(n,false);
    for(int i=0;i<n;i++) cin>>h[i];
    dp[0]=true;
    for(int i=1;i<n;i++){
        for(int j=1;j>=0;j--){
            if(h[i]-j>=h[i-1]){
                if(dp[i-1]){
                    dp[i]=true;
                    h[i]-=j;
                    break;
                }
            }
            dp[i]=false;
        }
    }
    if(dp[n-1]) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}