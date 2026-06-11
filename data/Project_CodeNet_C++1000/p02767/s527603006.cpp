#include <bits/stdc++.h>
#define rep(i, n)	for(int i=0;i<(int)(n);i++)
using namespace std;
using ll=long long;

int main(){
    int n;
    cin>>n;
    int x[100];
    double sum;
    rep(i,n){
        cin>>x[i];
        sum+=x[i];
    }
    int p=round(sum/n);
    int ans=0;
    rep(i,n){
        int diff=p-x[i];
        ans+=pow(diff,2);
    }
    cout<<ans<<endl;
}