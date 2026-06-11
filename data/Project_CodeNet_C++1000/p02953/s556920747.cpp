#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> h(n);
    int maxv=0;
    int num;
    rep(i,n){
        cin>>h[i];
        /*if(maxv<h[i]){
            maxv=h[i];
            num=i;
        }*/
    }
    bool flag=true;
    /*for(int i=num;i<n;i++){
        if(h[num]-h[i]>=2){
            flag=false;
            break;
        }
    }*/

    for(int i=n-2;i>0;i--){
        if(h[i]-h[i+1]==1) h[i]-=1;
        else if(h[i+1]<h[i]){
            flag=false;
            break;
        }
    }

    if(flag) cout<<"Yes"<<"\n";
    else cout<<"No"<<"\n";
    return 0;
}