#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> num(1005,0);
    
    rep(i,n) cin>>a[i];
    
    bool flag=true;
    
    rep(i,n){
        if(a[i]%2==0){
            if(a[i]%3!=0 && a[i]%5!=0){
                flag=false;
                break;
            }
        }
    }

    
    if(flag) cout<<"APPROVED"<<endl;
    else cout<<"DENIED"<<endl;
    
    return 0;
}