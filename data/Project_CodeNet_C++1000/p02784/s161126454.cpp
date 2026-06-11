#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;
using namespace std;

int main(){
    int h,n;
    cin>>h>>n;
    
    vector<int> a(n);
    rep(i,n) cin>>a[i];
    
    sort(a.begin(),a.end());
    bool flag=false;
    rep(i,n){
        h-=a[i];
        if(h<=0){
            flag=true;
            break;
        }
    }
    
    if(flag) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    
    return 0;
}