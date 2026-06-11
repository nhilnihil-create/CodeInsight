#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long ;
int main()
{
    int n;
    cin>>n;
    vector<int> a(n),b(n);
    rep(i,n) cin>>a[i];
    b=a;
    sort(b.begin(),b.end());
    rep(i,n){
        if(a[i]==b[n-1]) cout<<b[n-2]<<endl;
        else cout<<b[n-1]<<endl;
    }
}