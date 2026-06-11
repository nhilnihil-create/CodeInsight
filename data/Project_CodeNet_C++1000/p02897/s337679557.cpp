#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
#define repx(i,x,n) for(int i=x;i<n;i++)


int main(void) {
    int n;cin>>n;
    int cnt=0;
    repx(i,1,n+1)if(i%2!=0)cnt++;
    double ans=(double)cnt/n;
    cout<<ans;
}