#include <iostream>
using namespace std;
#define max 100000
typedef long long llong;

int n,k;
llong w[max];

int check(llong p){
    llong res=p;
    int cnt=0;
    int i=0;
    while (k>cnt) {
        if(res>w[i]){
            res-=w[i];
            i++;
        }else{
            res=p;
            cnt++;
        }
    }
    return i;
}

int solve(){
    llong left=0;
    llong right=100000*10000;
    llong mid;
    while (right-left>1) {
        mid=(left+right)/2;
        int v=check(mid);
        if(v>=n)right=mid;
        else left=mid;
    }
    return left;
}

int main(){
    cin>>n>>k;
    for (int i=0; i<n; i++)cin>>w[i];
    llong ans=solve();
    cout<<ans<<endl;
}
