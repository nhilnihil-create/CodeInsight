#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;
int main()
{
    int n,x,num=101,ans=101;
    cin>>x>>n;
    vector<int> a(110);
    rep(i,n){
        int b;
        cin>>b;
        a[b]++;
    }
    rep(i,102){
        if(a[i]==1) continue;
        if(num>abs(i-x)){
            num=abs(i-x);
            ans=i;
        }
    }
    cout<<ans;
}