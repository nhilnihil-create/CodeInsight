#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long ;
int main()
{
    int n;
    cin>>n;
    vector<int> h(n);
    rep(i,n) cin>>h[i];
    int now=h[0]-1;
    for(int i=1;i<n;i++){
        if(now>h[i]){
            cout<<"No";
            return 0;
        }
        if(now<h[i]){
            now=h[i]-1;
        }
    }
    cout<<"Yes";
}