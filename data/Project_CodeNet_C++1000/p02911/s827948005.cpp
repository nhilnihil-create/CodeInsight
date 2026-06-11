#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;

int main()
{
    int n,k,q;
    cin>>n>>k>>q;
    vector<int> a(n+1);
    rep(i,q){
        int b;
        cin>>b;
        a[b]++;
    }
    for(int i=1;i<=n;i++){
        if(k-q+a[i]<=0) cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
}