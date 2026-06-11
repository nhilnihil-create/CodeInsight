#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    double sum=0;
    cin>>n;
    rep(i,n) {
        int a;
        cin>>a;
        sum+=1.0/a;
    }
    double ans=1.0/sum;
    cout<<ans<<endl;
}