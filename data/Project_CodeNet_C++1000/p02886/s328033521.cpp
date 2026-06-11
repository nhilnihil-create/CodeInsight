#include <bits/stdc++.h>
#define rep(i, n)	for(int i=0;i<(int)(n);i++)
using namespace std;
using ll=long long;

int main(){
    int n;
    cin>>n;
    int d[n];
    rep(i, n) cin>>d[i];
    int ans=0;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            ans += d[i]*d[j];
        }
    }
    cout <<ans<<endl;
}