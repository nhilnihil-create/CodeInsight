#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)

using ll=long long;
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> d(n);
    rep(i,n) cin>>d[i];
    
    int center=n/2;
    sort(d.begin(),d.end());
    
    if(d[center]==d[center-1]) cout<<0<<endl;
    else{
        cout<<d[center]-d[center-1]<<endl;
    }
    
    return 0;
}