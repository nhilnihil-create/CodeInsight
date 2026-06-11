#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;
using namespace std;

int main(){
    int n;
    cin>>n;
    
    map<int,int> ans;
    
    rep(i,n){
        int a;
        cin>>a;
        ans[a]++;
    }
    
    bool flag=true;
    for(auto inter=ans.begin();inter!=ans.end();inter++){
        if(inter->second>=2){
            flag=false;
            break;
        }
    }
    
    if(flag) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    
    return 0;
}