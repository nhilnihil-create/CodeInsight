#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll=long long;
using P =pair<int,int>;

int main(){
    int n;
    int ans=100;
    cin>>n;
    vector<int>w(n);
    rep(i,n)cin>>w[i];
    rep(i,n){
        int s1=0;
        int s2=0;
        for(int j=0;j<=i;j++){
            s1=s1+w[j];
        }
        for(int k=i+1;k<n;k++){
            s2=s2+w[k];

        }
    ans=min(ans,abs(s1-s2));


    }
    cout<<ans;


}